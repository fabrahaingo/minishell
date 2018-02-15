/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:18:34 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/25 19:18:35 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_lastdir(char *path)
{
	int		i;
	int		tmp;
	char	*lastdir;

	i = 0;
	tmp = 0;
	lastdir = NULL;
	if (!path)
		return (NULL);
	while (path[i])
	{
		if (path[i] == '/')
			tmp = i;
		i++;
	}
	if (path[1])
		lastdir = ft_strdup(path + tmp + 1);
	else
		lastdir = ft_strdup(path + tmp);
	return (lastdir);
}
