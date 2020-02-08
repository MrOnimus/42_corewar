/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_to_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:39:54 by immn              #+#    #+#             */
/*   Updated: 2020/02/08 23:21:21 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	check_newline(int fd)//nl_in_eof
{
	char buf[1];

	lseek(fd, -1, SEEK_END);
	read(fd, buf, 1);
	if (*buf != '\n')
	{
		g_error.id = 16;
		return (1);
	}
	lseek(fd, 0, SEEK_SET);
	return (0);
}

void		cook_raw(int fd/*, t_out **out, char *filename*/)//translation
{
	t_out	*output;

	if (check_newline(fd))//check ONE new_line in eof
		return ;
	if (!(output = ft_memalloc(sizeof(t_out))))
	{
		g_error.id = 20;
		return ;
	}
	read_n_c(fd, output);
	if (g_error.id || read_code(fd, output))
	{
		del_output(&output);
		return ;
	}
	// write_magic(output);
	// to_file(output, filename);
	// *out = output;
	// del_output(out);
}
