/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:49:34 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/30 15:08:57 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_gohome(char **tab, char **env)
{
	char *tmp;

	tmp = NULL;
	if (!tab[1])
	{
		free(tab[0]);
		tmp = ft_strdup(ft_getenv("HOME", env));
		tab[0] = ft_strdup(tmp);
		free(tmp);
	}
	else if (!ft_strcmp(tab[1], "~"))
	{
		free(tab[1]);
		tab[1] = ft_strdup(ft_getenv("HOME", env));
	}
	else
		return (1);
	return (0);
}

static int	ft_basics(char **tab, char **env)
{
	char *tmp;
	char *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (*env == NULL)
		return (0);
	if (!ft_gohome(tab, env))
		;
	else if (!ft_strcmp(tab[1], "."))
	{
		free(tab[1]);
		tab[1] = ft_strdup(ft_getenv("PWD", env));
	}
	else if (!ft_strcmp(tab[1], ".."))
	{
		tmp = ft_strdup(ft_getenv("PWD", env));
		tmp2 = ft_path_up(tmp);
		free(tab[1]);
		tab[1] = ft_strdup(tmp2);
		free(tmp2);
	}
	else
		return (1);
	return (0);
}

static void	ft_changepwd(char **tab, char ***env)
{
	char **tmp;

	tmp = *env;
	if (!tab[1] && chdir(tab[0]) != -1)
	{
		ft_real_setenv("OLD_PWD", ft_getenv("PWD", tmp), &tmp);
		ft_setenv("PWD", tab[0], tmp);
	}
	else if (chdir(tab[1]) != -1)
	{
		ft_real_setenv("OLD_PWD", ft_getenv("PWD", tmp), &tmp);
		ft_setenv("PWD", tab[1], tmp);
	}
	else
		ft_putendl("minishell: this directory does not exist");
	*env = tmp;
}

void		ft_cd(char **tab, char ***env)
{
	char	*tmp;

	if (ft_basics(tab, *env) == 0)
		;
	else if (ft_letter_there(tab[1], '/'))
		ft_ispath(&tab, *env);
	else if (!ft_strcmp(tab[1], "-"))
	{
		free(tab[1]);
		tab[1] = ft_strdup(ft_getenv("OLD_PWD", *env));
	}
	else
	{
		if (ft_dir_there(tab[1], *env) == 1)
		{
			if (ft_strcmp(ft_getenv("PWD", *env), "/") != 0)
				tmp = ft_strjoin("/", tab[1]);
			else
				tmp = ft_strdup(tab[1]);
			free(tab[1]);
			tab[1] = ft_strjoin(ft_getenv("PWD", *env), tmp);
			free(tmp);
		}
	}
	ft_changepwd(tab, env);
}
