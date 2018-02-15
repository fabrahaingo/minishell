/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:12:55 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/06 20:12:56 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**ft_new_tab(char **tab, char *path, int i, int j)
{
	while (path[i])
	{
		if (path[i] == ':')
			j++;
		i++;
	}
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (j + 3));
	return (tab);
}

static int	ft_complete_tab(char *path, char **tab, int idx, int j)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (path[i] == ':')
		{
			tab[idx] = (char *)ft_memalloc(sizeof(char) * (i - j) + 1);
			tab[idx] = ft_strncpy(tab[idx], path + j, i - j);
			j = i + 1;
			idx++;
		}
		i++;
	}
	return (idx);
}

static int	ft_get_j(char *path)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == ':')
			j = j + 1;
		i++;
	}
	return (j);
}

char		**ft_parse_tab(char *path)
{
	int		j;
	int		idx;
	int		len;
	char	**tab;

	idx = 0;
	j = 0;
	tab = NULL;
	len = ft_strlen(path);
	tab = ft_new_tab(tab, path, 0, j);
	idx = ft_complete_tab(path, tab, idx, j);
	j = ft_get_j(path);
	tab[idx] = (char *)ft_memalloc(sizeof(char) * (len - j) + 1);
	tab[idx] = ft_strncpy(tab[idx], path + j, len - j);
	tab[idx + 1] = (char *)ft_memalloc(sizeof(char) * 2);
	tab[idx + 1] = ft_strncpy(tab[idx + 1], ".", 1);
	tab[idx + 2] = NULL;
	return (tab);
}
