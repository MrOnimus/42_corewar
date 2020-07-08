/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mark.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:17:44 by immn              #+#    #+#             */
/*   Updated: 2020/02/20 16:13:20 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t		replace_marks(t_tokens *read, t_mark *mark)//move_marks
{
	size_t	n;

	n = 0;
	while (read)
	{
		if (!read->a1 && !read->a2 && !read->a3)
		{
			//printf("1 - %s\n", read->command->cmd);
			n += weight(read);
		}
		else
		{
			//printf("2 - %s\n", read->command->cmd);
			if (read->a1)
				read->values[0] = calc_mark(read->a1, mark) - n;
			if (read->a2)
				read->values[1] = calc_mark(read->a2, mark) - n;
			if (read->a3)
				read->values[2] = calc_mark(read->a3, mark) - n;
			n += weight(read);
			ft_strdel(&read->a1);
			ft_strdel(&read->a2);
			ft_strdel(&read->a3);
		}
		read = read->next;
	}
	del_marks(mark);
	return (n);
}

int			calc_mark(char *name, t_mark *marks)//mark_position
{
	int	pos;

	pos = 0;
	while (marks)
	{
		if (!ft_strcmp(marks->mark, name))
		{
			pos = marks->size;
			break ;
		}
		marks = marks->next;
	}
	if (!marks)
	{
		g_error.id = 14;
		free(g_error.str_er);
		g_error.str_er = ft_strdup(name);
	}
	return (pos);
}

static size_t	weight_arg(char type, char dir_size)
{
	size_t	n;

	n = 0;
	if (type == T_DIR)
		n += dir_size;
	else if (type == T_IND)
		n += 2;
	else
		n += type;
	return (n);
}

size_t			weight(t_tokens *me)
{
	size_t	n;

	n = 0;
	if (!me->command)
		return (0);
	n += 1;
	if (me->command->a_typecode)
		n += 1;
	n += weight_arg(me->types[0], me->command->dir_size);
	n += weight_arg(me->types[1], me->command->dir_size);
	n += weight_arg(me->types[2], me->command->dir_size);
	return (n);
}

t_mark		*fill_mark(t_tokens *read, char status)
{
	size_t	n;
	t_mark	*mark;
	t_mark	*start;

	n = 0;
	mark = NULL;
	start = NULL;
	while (read)
	{
		if (read->mark && label_correct(read->mark))
		{
			start = ft_memalloc(sizeof(t_mark));
			start->next = mark;
			start->mark = read->mark;
			read->mark = NULL;
			start->size = n;
			mark = start;
		}
		else if (read->mark && (g_error.id = 15) &&
		(g_error.str_er = read->mark) && (status = 1))
			return (NULL);
		n += weight(read);
		read = read->next;
	}
	return (start);
}
