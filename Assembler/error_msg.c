/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:21:18 by immn              #+#    #+#             */
/*   Updated: 2020/02/05 13:03:22 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_msg[20] = {
	"\033[31m; can't allocate memory\n\033[0m",
	"\033[31m doesn't exist or invalid\n\033[0m",
	"\033[31m have incorrect extension  [must be \".s\"]\n\033[0m",
	"\033[31m; champion name is not correct\n\033[0m",
	"\033[31m; champion comment is not correct\n\033[0m",
	"\033[31m; double name\n\033[0m",
	"\033[31m; double comment\n\033[0m",
	"\033[31m; no name\n\033[0m",
	"\033[31m; no comment\n\033[0m",
	"\033[31m can't be created new file\n\033[0m",
	"\033[31m incorrect command:   \033[0m",
	"\033[31m incorrect argument:   \033[0m",
	"\033[31m incorrect number of arguments:   \033[0m",
	"\033[31m incorrect command:   \033[0m",
	"\033[31m this label doesn't exist:   \033[0m",
	"\033[31m incorrect label:   \033[0m",
	"\033[31m there is no newline at the end of the file \n\033[0m",
	"\033[31m champion name is too long \n\033[0m",
	"\033[31m champion comment is too long \n\033[0m",
	"\033[31m champion has no command \n\033[0m"
 };

t_error		g_error = {NULL, 0, NULL};

void		say_error(char *fname)
{
	ft_putstr_fd("\033[31mThe file \033[0m", 2);
	ft_putstr_fd(g_error.filename, 2);
	ft_putstr_fd(g_msg[g_error.id], 2);
	if (g_error.id > 9 && g_error.id < 16)
	{
		ft_putendl_fd(g_error.str_er, 2);
	}
	g_error.id = 0;
	ft_strdel(&g_error.str_er);
	ft_strdel(&fname);
}
