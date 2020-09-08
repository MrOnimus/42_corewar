/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_part_of_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 02:28:02 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/09/08 21:16:28 by aschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_full_dotval(int fd, size_t max_length, char *start, char *tmp)
{
	char	*end;
	char	*str;

	if ((end = ft_strchr(start, '"')))
		str = ft_strsub(start, 0, end - start);
	else
	{
		str = ft_strdup(start);
		while (get_next_line(fd, &start) && !(end = ft_strchr(start, '"')))
			str = ft_strjoin_free(str, start, 3);
		tmp = ft_strsub(start, 0, end - start);
		str = ft_strjoin_free(str, tmp, 3);
		ft_strdel(&start);
	}
	if (end && ft_strlen(str) <= max_length && check_for_comment(end + 1) != -1)
		return (str);
	ft_strdel(&str);
	if (check_for_comment(end + 1) == -1)
		g_error.id = 3;
	else
		g_error.id = end ? 17 : 3;
	return (NULL);
}

static void	read_dotval(int fd, t_out *out, char *line, int flag)
{
	char	*start;
	char	*name;
	char	*tmp;
	int		max_length;

	tmp = NULL;
	if ((!(start = ft_strchr(line, '"')) || !ft_strnempty(line, start - line))
		&& (g_error.id = 4 + (flag - 1)))
		return ;
	max_length = !(flag) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	if ((name = get_full_dotval(fd, max_length, start + 1, tmp)))
	{
		if (flag)
			ft_strcpy(out->comm, name);
		else
			ft_strcpy(out->name, name);
		ft_strdel(&name);
	}
	else
		g_error.id += flag;
	if (!flag)
		out->n_exist = 1;
	else
		out->c_exist = 1;
}

int			preread_dotval(int fd, t_out *out, char *line)
{
	size_t	n_len;
	size_t	c_len;

	n_len = ft_strlen(NAME_CMD_STRING);
	c_len = ft_strlen(COMMENT_CMD_STRING);
	if (line && !ft_strncmp(COMMENT_CMD_STRING, line, c_len))
	{
		if (out->c_exist && (g_error.id = 6) && del_str(&line))
			return (-1);
		read_dotval(fd, out, line + c_len, 1);
		return (1);
	}
	else if (line && !ft_strncmp(NAME_CMD_STRING, line, n_len))
	{
		if (out->n_exist && (g_error.id = 5) && del_str(&line))
			return (-1);
		read_dotval(fd, out, line + n_len, 0);
		return (1);
	}
	return (0);
}

void		get_name_n_comment(int fd, t_out *out)
{
	char	*line;
	char	*tmp;

	line = NULL;
	while (!out->c_exist || !out->n_exist)
	{
		while (get_next_line(fd, &line) && (!*line || *line == COMMENT_CHAR
					|| *line == ALT_COMMENT_CHAR))
			ft_memdel((void**)&line);
		tmp = ft_strtrim(line);
		if (preread_dotval(fd, out, tmp) == 1)
			;
		else if (!line && (g_error.id = out->c_exist ? 7 : 8) && del_str(&line)
				&& del_str(&tmp))
			return ;
		ft_strdel(&tmp);
		ft_strdel(&line);
	}
}
