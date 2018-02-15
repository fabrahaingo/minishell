/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:22:29 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/05 18:22:30 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_deltabstring(int i, char ***env)
{
	char **tmp;

	tmp = *env;
	if (!tmp[i])
		return ;
	while (tmp[i + 1])
	{
		ft_strdel(&tmp[i]);
		tmp[i] = ft_strdup(tmp[i + 1]);
		i++;
	}
	ft_strdel(&tmp[i]);
	*env = tmp;
}

void		ft_unsetenv(char *name, char ***env)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *env;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], name, ft_strlen(name)) == 0)
		{
			ft_deltabstring(i, &tmp);
			*env = ft_realloc(tmp, i + 1, i);
			return ;
		}
		i++;
	}
	ft_putendl("minishell: no such environment value");
}
