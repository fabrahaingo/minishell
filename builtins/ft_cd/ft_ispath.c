/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:09:53 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/06 15:09:55 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_currpath(char **tab, int i, int len)
{
	char *tmp1;
	char *tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (tab[1][i + 1] == '\0')
	{
		tmp1 = ft_strcutend(tab[1], 2);
		tab[1] = ft_strdup(tmp1);
		free(tmp1);
	}
	if (tab[1][i + 1] == '/')
	{
		tmp1 = ft_strnew(i + 1);
		tmp1 = ft_strncpy(tmp1, tab[1], i - 1);
		tmp2 = ft_strnew(len - i);
		tmp2 = ft_strcpy(tmp2, tab[1] + i + 1);
		free(tab[1]);
		tab[1] = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
	}
}

static void	ft_prevpath(char **tab, int i)
{
	char *tmp1;
	char *tmp2;
	char *clone;

	tmp1 = NULL;
	tmp2 = NULL;
	clone = NULL;
	if (tab[1][i + 2] == '\0')
	{
		clone = ft_path_up(ft_strcutend(tab[1], 3));
		tab[1] = ft_strdup(clone);
		free(clone);
	}
	else if (tab[1][i + 2] == '/')
	{
		tmp1 = ft_strnew(i);
		tmp1 = ft_strncpy(tmp1, tab[1], i - 1);
		tmp2 = ft_strdup(tab[1] + i + 2);
		free(tab[1]);
		clone = ft_path_up(tmp1);
		tab[1] = ft_strjoin(clone, tmp2);
		free(clone);
		free(tmp2);
	}
}

static void	ft_slashend(char **tab, int i)
{
	char *tmp1;
	char *tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	tmp1 = ft_strnew(i);
	tmp1 = ft_strncpy(tmp1, tab[1], i);
	tmp2 = ft_strdup(tab[1] + i + 1);
	free(tab[1]);
	tab[1] = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

void		ft_ispath(char ***table, char **env)
{
	int		i;
	int		len;
	char	**tab;

	tab = *table;
	i = 0;
	len = 0;
	while (tab[1][i])
	{
		len = ft_strlen(tab[1]);
		ft_signstart(tab, env);
		if (tab[1][i] == '/' && (tab[1][i + 1] == '/' || !tab[1][i + 1]))
		{
			ft_slashend(tab, i);
			i = 0;
			break ;
		}
		if (tab[1][i] == '.' && tab[1][i - 1] == '/' && tab[1][i + 1] != '.')
		{
			ft_currpath(tab, i, len);
			i = 0;
			continue;
		}
		if (tab[1][i] == '.' && tab[1][i - 1] == '/' && tab[1][i + 1] == '.')
		{
			ft_prevpath(tab, i);
			i = 0;
			continue;
		}
		i++;
	}
	*table = tab;
}
