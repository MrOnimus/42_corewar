/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_to_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:39:54 by immn              #+#    #+#             */
/*   Updated: 2020/02/24 16:59:03 by immn             ###   ########.fr       */
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

void		cook_raw(int fd, t_out **out, char *filename)//translation
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
	//вывод перенести в отдельную функцию
	write_magic(output);
	to_file(output, filename);
	*out = output;
	del_output(out);
}
