/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:56:02 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/30 14:34:36 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**ft_fill_tab(char *str)
{
	size_t	i;
	int		j;
	char	**tab;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while ((tmp = ft_parse_ident(str, &i)))
	{
		j++;
		free(tmp);
	}
	tab = (char **)ft_memalloc(sizeof(char *) * (j + 1));
	j = 0;
	i = 0;
	while ((tmp = ft_parse_ident(str, &i)))
	{
		tab[j] = ft_strdup(tmp);
		free(tmp);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
