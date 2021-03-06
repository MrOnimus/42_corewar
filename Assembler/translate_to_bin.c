/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_to_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:39:54 by immn              #+#    #+#             */
/*   Updated: 2020/05/01 19:54:02 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void					to_file(t_out *output, char *filename)
{
	int	fd;

	if ((fd = open(filename, O_WRONLY | O_CREAT, 0600)) < 3)
		g_error.id = 10;
	write(fd, &output->head, 4);
	write(fd, &output->name, PROG_NAME_LENGTH);
	write(fd, &output->name_null, 4);
	write(fd, &output->code_size, 4);
	write(fd, &output->comm, COMMENT_LENGTH);
	write(fd, &output->com_null, 4);
	write(fd, output->code, output->code_size_int);
	close(fd);
}

void	write_magic(t_out *out)
{
	char	*cast;
	int		value;
	int		i;
	int		j;

	i = -1;
	j = 4;
	value = COREWAR_EXEC_MAGIC;
	cast = (char*)&value;
	while (++i < 4)
		out->head[--j] = *(cast + i);
}

static char	nl_in_eof(int fd)
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

void		translation(int fd, t_out **out, char *filename)
{
	t_out	*output;

	if (nl_in_eof(fd))//check ONE new_line in eof
		return ;
	if (!(output = ft_memalloc(sizeof(t_out))))
	{
		g_error.id = 20;
		return ;
	}
	get_name_n_comment(fd, output);
	if (g_error.id || read_instructions(fd, output))
	{
		del_output(&output);
		return ;
	}
	write_magic(output);
	to_file(output, filename);
	*out = output;
	del_output(out);
}
