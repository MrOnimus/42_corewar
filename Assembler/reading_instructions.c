/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:04:25 by immn              #+#    #+#             */
/*   Updated: 2020/02/10 16:11:42 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op		*check_command(char *l, size_t pos)//cmp_commands
{
	int		i;

	if (pos > 5 && (g_error.id = 10))
		return (NULL);
	i = -1;
	while (++i < NUMBER_OF_COMMAND)
		if (ft_strnequ(l, (char *)&(g_op_tab[i].cmd), pos))
			return (&g_op_tab[i]);
	printf("!!\n");
	g_error.id = 10;
	return (NULL);
}

t_tokens	*check_line(char *line)//parse_line
{
	t_tokens	*new;
	size_t		pos;
	char		feedback;

	skip_emptyness(&line);
	if (*line == COMMENT_CHAR || !*line)
		return (NULL);
	//feedback - marker of separator
	/*
		1 - :
		2 - %
		3 - ,
		0 - prblm
	*/
	if (!(feedback = find_sep(line, &pos)) || (feedback == 3))
	{ 
		return ((g_error.id = 10) ? NULL : NULL);
	}
	if (!(new = ft_memalloc(sizeof(t_tokens))))
		return ((g_error.id = 20) ? NULL : NULL);
	if (feedback == 1)
	{
		new->mark = ft_strsub(line, 0, pos);
		line += pos + 1;
		skip_emptyness(&line);
		if ((feedback = find_sep(line, &pos)) == 0)//for lable
			return (new);
		if (feedback != 2)
			return (free_return(new));
	}
	if (!(new->command = check_command(line, pos)) ||
		parse_args(line + pos + 1, new))
		return (free_return(new));
	return (new);
}

static t_tokens	*validate(int fd)//validate_n_build_list
{
	char		*line;
	t_tokens	*toks;
	t_tokens	*curr;
	t_tokens	*new;

	toks = NULL;
	curr = NULL;
	while (get_next_line(fd, &line))
	{
		if ((new = check_line(line)))
		/**
		 * 1. Нужно протетировать функцию check_line
		 * 		Можно просто смотреть по кодам ошибки по ходу программы и пытаться их провоцировать
		 * 2. Строчка вида:
		 * 	name_lable:			; Alternative comment with space after ";"
		 * 	выдает ошибку.
		 * 	В остальных местах альтернативный комментарий отрабатывает.
		 * 
		**/
		{
			add_tok(&toks, &curr, new);
			//printf("kek\n");
		}
		if (g_error.id && (g_error.str_er = line))
		{
			line = NULL;
			del_tokens(toks);
			return (NULL);
		}
		ft_strdel(&line);
	}
	if (curr)
		curr->next = NULL;
	if (!toks && (g_error.id = 19))
		return (NULL);
	return (toks);
}

int					read_code(int fd, t_out *out)//read_instructions
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