/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:06:38 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/09 13:50:28 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_builtins(char **tab, char ***env)
{
	char **tmp;

	tmp = *env;
	if (!ft_strcmp(tab[0], "cd"))
		ft_cd(tab, &tmp);
	else if (!ft_strcmp(tab[0], "pwd"))
		ft_putendl(ft_getenv("PWD", tmp));
	else if (!ft_strcmp(tab[0], "echo"))
		ft_echo(tab);
	else if (!ft_strcmp(tab[0], "env"))
		ft_env(tmp);
	else if (!ft_strcmp(tab[0], "setenv"))
		ft_real_setenv(tab[1], tab[2], &tmp);
	else if (!ft_strcmp(tab[0], "unsetenv"))
		ft_unsetenv(tab[1], &tmp);
	else
		return (0);
	*env = tmp;
	return (1);
}

static void	ft_commands(char **tab, char ***env)
{
	char	*file;
	pid_t	pid;

	file = NULL;
	if (!tab)
		return ;
	if (ft_builtins(tab, env) != 0)
		;
	else if ((file = ft_binary_there(ft_getenv("PATH", *env), tab[0])))
	{
		pid = fork();
		if (pid == 0)
			execve(file, tab, *env);
		else
		{
			waitpid(pid, NULL, 0);
			ft_strdel(&file);
			return ;
		}
	}
	else
		ft_notfound(tab);
	ft_strdel(&file);
}

static int	ft_prompt(char **env, char **str)
{
	char	*tmp;
	int		ret;

	tmp = NULL;
	tmp = ft_lastdir(ft_getenv("PWD", env));
	ft_putstr(tmp);
	ft_strdel(&tmp);
	ft_putstr("> ");
	ret = get_next_line(0, str);
	if (!ft_strcmp(*str, "exit"))
	{
		ft_strdel(str);
		return (0);
	}
	return (ret);
}

static void	ft_heart(char *str, char ***env)
{
	int		i;
	char	**tab;
	char	**tmp;

	tmp = *env;
	tab = ft_fill_tab(str);
	ft_commands(tab, &tmp);
	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	ft_memdel((void **)&tab);
	*env = tmp;
}

int			main(int argc, char **argv, char **env)
{
	char	*str;
	int		i;

	ft_initialize(&str, &i);
	if (argc != 1 || !argv)
		return (-1);
	env = ft_envinit(env);
	while (1)
	{
		if (ft_prompt(env, &str) <= 0)
		{
			ft_strdel(&str);
			break ;
		}
		if (ft_empty(str))
			ft_strdel(&str);
		if (!str)
			continue;
		ft_heart(str, &env);
		ft_strdel(&str);
	}
	while (env[i])
		ft_strdel(&env[i++]);
	free(env);
	return (0);
}
