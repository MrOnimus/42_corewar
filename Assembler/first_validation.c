/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 06:54:23 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/08 21:07:46 by aschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*check_valid_name(char *name)
{
	char *p;
	char *tmp;
	char *new;

	p = ft_strstr(name, ".s");
	if (!p || *(p + 2))
		return (NULL);
	tmp = ft_strsub(name, 0, p - name);
	new = ft_strjoin(tmp, ".cor");
	free(tmp);
	return (new);
}

void	success_msg(char *fname)
{
	ft_putstr_fd("\033[0;32mThe file : \033[0m", 1);
	ft_putstr_fd(g_error.filename, 1);
	ft_putstr_fd(" \033[32m ...Writing output to: \033[0m", 1);
	ft_putendl_fd(fname, 1);
	ft_strdel(&fname);
	g_error.id = 0;
	g_error.str_er = NULL;
}
