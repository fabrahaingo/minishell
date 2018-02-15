/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signstart.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 03:01:40 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/10 03:01:41 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_norm(char **tab, char **env)
{
	char *tmp1;

	tmp1 = NULL;
	if (tab[1][0] != '/' && tab[1][0] != '.' && tab[1][0] != '~')
	{
		tmp1 = ft_strjoin("/", tab[1]);
		free(tab[1]);
		tab[1] = ft_strjoin(ft_getenv("PWD", env), tmp1);
		free(tmp1);
	}
	if (tab[1][0] == '~' && tab[1][1] == '/')
	{
		tmp1 = ft_strjoin("/", tab[1] + 2);
		free(tab[1]);
		tab[1] = ft_strjoin(ft_getenv("HOME", env), tmp1);
		free(tmp1);
	}
}

void		ft_signstart(char **tab, char **env)
{
	char *tmp1;
	char *clone;
	char *clone2;

	tmp1 = NULL;
	clone = NULL;
	clone2 = NULL;
	ft_norm(tab, env);
	if (tab[1][0] == '.' && tab[1][1] == '/')
	{
		tmp1 = ft_strjoin("/", tab[1] + 2);
		free(tab[1]);
		tab[1] = ft_strjoin(ft_getenv("PWD", env), tmp1);
		free(tmp1);
	}
	if (tab[1][0] == '.' && tab[1][1] == '.' && tab[1][2] == '/')
	{
		tmp1 = ft_strdup(tab[1] + 2);
		free(tab[1]);
		clone = ft_strdup(ft_getenv("PWD", env));
		clone2 = ft_path_up(clone);
		tab[1] = ft_strjoin(clone2, tmp1);
		free(clone2);
		free(tmp1);
	}
}
