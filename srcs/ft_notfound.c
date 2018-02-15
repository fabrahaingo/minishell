/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notfound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:06:00 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/07 19:06:02 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_notfound(char **tab)
{
	int i;

	i = 0;
	if (tab[i])
		if (access(tab[i], R_OK))
		{
			ft_putstr("minishell: command not found: ");
			ft_putendl(tab[i]);
		}
}
