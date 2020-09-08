/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mark.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:20:44 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/08 21:12:42 by aschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t			move_marks(t_tokens *read, t_mark *mark)
{
	size_t	n;

	n = 0;
	while (read)
	{
		if (!read->a1 && !read->a2 && !read->a3)
			n += weight(read);
		else
		{
			if (read->a1)
				read->values[0] = mark_position(read->a1, mark) - n;
			if (read->a2)
				read->values[1] = mark_position(read->a2, mark) - n;
			if (read->a3)
				read->values[2] = mark_position(read->a3, mark) - n;
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

int				mark_position(char *name, t_mark *marks)
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

t_mark			*fill_mark(t_tokens *read, char status)
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
				(g_error.str_er = read->mark) && (status == 1))
			return (NULL);
		n += weight(read);
		read = read->next;
	}
	return (start);
}
