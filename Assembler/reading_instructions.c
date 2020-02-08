/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:04:25 by immn              #+#    #+#             */
/*   Updated: 2020/02/08 23:20:54 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					read_code(int fd, t_out *out)
{
	t_tokens	*read;
	// t_mark		*mark;
	// char		status;

	if (!(read = validate(fd)))
		return (1);
	// status = 0;
	// mark = fill_mark(read, status);
	// if (status == 1)
	// {
	// 	del_marks(mark);
	// 	del_tokens(read);
	// 	return (1);
	// }
	// read = del_empty(read);
	// out->code_size_int = replace_marks(read, mark);
	// code_to_bytes(read, out);
	// out->c_exist = 1;
	// del_tokens(read);
	// return (0);
}