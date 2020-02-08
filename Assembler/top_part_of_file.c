/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_part_of_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:51:11 by immn              #+#    #+#             */
/*   Updated: 2020/02/06 13:55:38 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		read_n_c(int fd, t_out *out)//get_name_n_comment
{
	// char	*line;
	size_t	n_len;
	size_t	c_len;

	calc_len(&n_len, &c_len);
	// line = NULL;
	// while (!out->c_exist || !out->n_exist)
	// {
	// 	while (get_next_line(fd, &line) && (!*line || *line == COMMENT_CHAR))
	// 		ft_memdel((void**)&line);
	// 	if (line && !ft_strncmp(COMMENT_CMD_STRING, line, c_len))
	// 	{
	// 		if (out->c_exist && (g_error.id = 6) && del_str(&line))
	// 			return ;
	// 		read_comment(fd, out, line + c_len);
	// 	}
	// 	else if (line && !ft_strncmp(NAME_CMD_STRING, line, n_len))
	// 	{
	// 		if (out->n_exist && (g_error.id = 5) && del_str(&line))
	// 			return ;
	// 		read_name(fd, out, line + n_len);
	// 	}
	// 	else if (!line && (g_error.id = out->c_exist ? 7 : 8) && del_str(&line))
	// 		return ;
	// 	ft_strdel(&line);
	// }
}
