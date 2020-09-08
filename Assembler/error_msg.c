/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:46:26 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/09/08 21:08:23 by aschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_msg[21] = {
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
	"\033[31m incorrect command:   \n\033[0m",
	"\033[31m incorrect argument:   \n\033[0m",
	"\033[31m incorrect number of arguments:   \n\033[0m",
	"\033[31m incorrect command:   \n\033[0m",
	"\033[31m this label doesn't exist:   \n\033[0m",
	"\033[31m incorrect label:   \n\033[0m",
	"\033[31m there is no newline at the end of the file \n\033[0m",
	"\033[31m champion name is too long \n\033[0m",
	"\033[31m champion comment is too long \n\033[0m",
	"\033[31m champion has no command \n\033[0m",
	"\033[31m; can't allocate memory\n\033[0m"
};

void		fail_msg(char *fname)
{
	ft_putstr_fd("\033[31mThe file \033[0m", 2);
	ft_putstr_fd(g_error.filename, 2);
	ft_putstr_fd(g_msg[g_error.id], 2);
	if (g_error.id > 9 && g_error.id < 16)
		ft_putendl_fd(g_error.str_er, 2);
	g_error.id = 0;
	ft_strdel(&g_error.str_er);
	if (fname)
		ft_strdel(&fname);
}
