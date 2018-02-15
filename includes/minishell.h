/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:07:38 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/09 11:14:16 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

char		**ft_fill_tab(char *str);
char		*ft_lastdir(char *path);
void		ft_cd(char **tab, char ***env);
void		ft_echo(char **tab);
void		ft_env(char **env);
void		ft_real_setenv(char *name, char *value, char ***env);
void		ft_unsetenv(char *name, char ***env);
void		ft_ispath(char ***tab, char **env);
char		**ft_parse_tab(char *path);
char		*ft_binary_there(char *path, char *file);
void		ft_notfound(char **tab);
void		ft_initialize(char **str, int *i);
char		*ft_parse_ident(const char *str, size_t *i);
int			ft_empty(char *str);
void		ft_signstart(char **tab, char **env);

#endif
