/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 15:48:56 by oargrave          #+#    #+#             */
/*   Updated: 2020/09/08 21:13:08 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op			*cmp_commands(char *l, size_t pos)
{
	int		i;

	if (pos > 5 && (g_error.id = 10))
		return (NULL);
	i = -1;
	while (++i < NUMBER_OF_COMMAND)
		if (ft_strnequ(l, (char *)&(g_op_tab[i].cmd), pos))
			return (&g_op_tab[i]);
	g_error.id = 10;
	return (NULL);
}

t_tokens		*parse_line(char *line)
{
	t_tokens	*new;
	size_t		pos;
	char		feedback;

	skip_emptyness(&line);
	if (*line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR || !*line)
		return (NULL);
	if (!(feedback = find_sep(line, &pos)) || (feedback == 3))
		return ((g_error.id = 10) ? NULL : NULL);
	if (!(new = ft_memalloc(sizeof(t_tokens))))
		return ((g_error.id = 20) ? NULL : NULL);
	if (feedback == 1)
	{
		new->mark = ft_strsub(line, 0, pos);
		line += pos + 1;
		skip_emptyness(&line);
		if ((feedback = find_sep(line, &pos)) == 0)
			return (new);
		if (feedback != 2)
			return (free_return(new));
	}
	if (!(new->command = cmp_commands(line, pos)) ||
		parse_args(line + pos + 1, new))
		return (free_return(new));
	return (new);
}

static t_tokens	*validate(int fd)
{
	char		*line;
	t_tokens	*toks;
	t_tokens	*curr;
	t_tokens	*new;

	toks = NULL;
	curr = NULL;
	while (get_next_line(fd, &line))
	{
		if ((new = parse_line(line)))
			add_tok(&toks, &curr, new);
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

int				read_instructions(int fd, t_out *out)
{
	t_tokens	*read;
	char		status;
	t_mark		*mark;

	if (!(read = validate(fd)))
		return (1);
	status = 0;
	mark = fill_mark(read, status);
	if (status == 1)
	{
		del_marks(mark);
		del_tokens(read);
		return (1);
	}
	read = del_empty(read);
	out->code_size_int = move_marks(read, mark);
	code_to_bytes(read, out);
	out->c_exist = 1;
	del_tokens(read);
	return (0);
}
