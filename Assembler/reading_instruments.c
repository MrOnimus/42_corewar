/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_instruments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:36:12 by immn              #+#    #+#             */
/*   Updated: 2020/02/10 15:50:19 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	skip_emptyness(char **p)
{
	while (**p == ' ' || **p == '\t')
		(*p)++;
}

char		find_sep(char *l, size_t *p)
{
	*p = 0;
	//printf("line = %s;", l);
	while (l[*p] && l[*p] != LABEL_CHAR && l[*p] != DIRECT_CHAR && l[*p] != ' '
		&& l[*p] != '\t' && l[*p] != SEPARATOR_CHAR && l[*p] != COMMENT_CHAR)
		(*p)++;
	//printf(" and char %c\n", l[*p]);
	if (l[*p] == LABEL_CHAR)
		return (1);
	if (l[*p] == DIRECT_CHAR || l[*p] == ' ' || l[*p] == '\t')
		return (2);
	if (l[*p] == SEPARATOR_CHAR)
		return (3);
		
	return (0);
}

void			check_for_comment(char *line)//crop_comment
{
	char	*p1;
	char	*p2;

	p1 = ft_strchr(line, COMMENT_CHAR);
	p2 = ft_strchr(line, ALT_COMMENT_CHAR);
	if (!p1 && !p2)
		return ;
//	printf("check comment %s\n", line);
	if ((p1 > p2 && p2) || !p1)
		*p2 = '\0';
	else if ((p2 > p1 && p1) || !p2)
		*p1 = '\0';
}

char			del_2mas(char **me)//free_two_dim_array
{
	char **start;

	start = me;
	while (*me)
	{
		free(*me);
		me++;
	}
	free(start);
	return (1);
}

char			label_correct(char *l)
{
	while (*l && ft_strchr(LABEL_CHARS, *l))
		l++;
	if (*l)
		return (0);
	return (1);
}
