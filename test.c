/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:54:26 by immn              #+#    #+#             */
/*   Updated: 2020/02/16 14:00:52 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char		fill_mark(char status)
{
	if (1 && (status = 54))
	{
			printf("status1 = %c\n", status);

		return (12);
	}
}

int					main(void)//read_instructions
{
	char		status;
	char 		mark;
	status = 49;
	printf("status = %c\n", status);
	mark = fill_mark(status);
	// if (status == 1)//Эта часть кода не отработает.
	// {
	// 	del_marks(mark);
	// 	del_tokens(read);
	// 	return (1);
	// }
	// read = del_empty(read);
	// out->code_size_int = move_marks(read, mark);
	// code_to_bytes(read, out);
	// out->c_exist = 1;
	// del_tokens(read);
	printf("status = %c\n", status);
	return (0);
}