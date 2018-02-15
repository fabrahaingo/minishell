/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ident.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:39:17 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/09 14:39:18 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*parse_ident_sub(const char *str, size_t *i)
{
	char	*tmp;
	char	*tmp_semi;

	while (str[*i] && ft_iswhitespace(str[*i]))
		(*i)++;
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		tmp = ft_strchr_esc(str + (*i + 1), str[*i]);
		*i += 1;
	}
	else
	{
		tmp = (char *)(str + (*i));
		while (*tmp && !ft_iswhitespace(*tmp))
			tmp++;
		if (*tmp == 0)
			tmp = 0;
		tmp_semi = ft_strchr(str + (*i), ';');
		if (tmp_semi && tmp_semi < tmp)
			tmp = tmp_semi;
		if (tmp == 0)
			tmp = tmp_semi;
	}
	return (tmp);
}

char		*ft_parse_ident(const char *str, size_t *i)
{
	char	*res;
	char	*tmp;
	size_t	len;

	res = 0;
	tmp = parse_ident_sub(str, i);
	if (tmp)
		len = tmp - (str + *i);
	else
		len = ft_strlen(str + *i);
	if (len == 0)
		return (0);
	if (!(res = ft_strnew(len)))
		return (0);
	ft_strncpy_esc(res, str + *i, len);
	*i += len;
	if (tmp && (*tmp == '\'' || *tmp == '\"'))
		*i += 1;
	return (res);
}
