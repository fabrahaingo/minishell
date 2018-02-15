/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_there.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:34:17 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/09 13:40:18 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_only_file(char *path)
{
	char	*file;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (path[i])
	{
		if (path[i] == '/')
			j = i;
		i++;
	}
	file = ft_strdup(path + j + 1);
	return (file);
}

static char	*ft_exist(char *file, char **tab)
{
	int			i;
	char		*tmp;
	char		*full_path;
	struct stat	buf;

	i = 0;
	full_path = NULL;
	while (tab[i])
	{
		tmp = ft_strjoin("/", file);
		full_path = ft_strjoin(tab[i], tmp);
		ft_strdel(&tmp);
		if (!stat(full_path, &buf))
		{
			ft_strdel(&file);
			return (full_path);
		}
		ft_strdel(&full_path);
		i++;
	}
	return (full_path);
}

static int	ft_ifpath(char **file)
{
	char *tmp;
	char *nf;

	if (ft_letter_there(*file, '/'))
	{
		tmp = ft_only_file(*file);
		nf = ft_strnew(ft_strlen(*file) + ft_strlen(tmp));
		ft_strcpy(nf, *file);
		ft_strcpy(nf, tmp);
		*file = nf;
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

char		*ft_binary_there(char *path, char *file)
{
	char		**tab;
	int			i;
	char		*full_path;

	i = 0;
	if (path == NULL)
		return (NULL);
	tab = ft_parse_tab(path);
	if (ft_ifpath(&file))
		;
	else
		file = ft_strdup(file);
	if ((full_path = ft_exist(file, tab)) != 0)
	{
		while (tab[i])
			ft_strdel(&tab[i++]);
		free(tab);
		return (full_path);
	}
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	ft_strdel(&file);
	return (NULL);
}
