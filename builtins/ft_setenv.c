/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:27:10 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/31 19:27:11 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_real_setenv(char *name, char *value, char ***env)
{
	char	**tmp1;
	int		i;
	char	*tmp2;
	char	*clone;

	tmp1 = *env;
	i = -1;
	while (tmp1[++i])
	{
		if (!ft_strncmp(tmp1[i], name, ft_strlen(name)))
		{
			clone = ft_strjoin(name, "=");
			free(tmp1[i]);
			tmp1[i] = ft_strjoin(clone, value);
			free(clone);
			*env = tmp1;
			return ;
		}
	}
	tmp1 = ft_realloc(tmp1, (i + 1) * sizeof(char *), (i + 2) * sizeof(char *));
	tmp2 = ft_strjoin(name, "=");
	tmp1[i] = ft_strjoin(tmp2, value);
	free(tmp2);
	tmp1[i + 1] = NULL;
	*env = tmp1;
}
