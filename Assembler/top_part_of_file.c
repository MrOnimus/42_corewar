/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_part_of_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:51:11 by immn              #+#    #+#             */
/*   Updated: 2020/03/10 22:00:29 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		del_3_str(char **s1, char **s2, char **s3) // TODO: От этого костыля стопроц надо избавляться, надо придумать что-то красивое
{
	del_str(s1);
	del_str(s2);
	del_str(s3);
}

static char	*give_full_name(int fd, size_t max_length, char *start, char *tmp)// TODO: Эту желательно разбить или сделать проще//save_that_attr
{
	char	*end;
	char	*str;
	char	*tmp2;

	if ((end = ft_strchr(start, '"')))
		str = ft_strsub(start, 0, end - start);
	else
	{
		str = ft_strdup(start);
		while (get_next_line(fd, &start) && !(end = ft_strchr(start, '"')))
		{
			tmp = str;
			str = ft_strjoin(str, start);
			del_3_str(&start, &tmp, NULL);
		}
		tmp = ft_strsub(start, 0, end - start);
		tmp2 = str;
		str = ft_strjoin(str, tmp);
		del_3_str(&tmp, &tmp2, &start);
	}
	if (end && ft_strlen(str) <= max_length)
		return (str);
	ft_strdel(&str);
	g_error.id = end ? 17 : 3;
	return (NULL);
}

static void	read_dotval(int fd, t_out *out, char *line, int flag)//read_name_or_com if flag == 0 its name, else - comment
{
	char	*start;
	char	*name;
	char	*tmp;

	tmp = NULL;
	if ((!(start = ft_strchr(line, '"')) || !is_empty(line, start - line))
		&& (g_error.id = 4 + (flag - 1)))
		return ;
	if ((name = give_full_name(fd, COMMENT_LENGTH, start + 1, tmp)))
	{
		ft_strcpy(out->comm, name);
		ft_strdel(&name);
	}
	else
		g_error.id += 1;
	if (!flag)
		out->n_exist = 1;
	else
		out->c_exist = 1;
}

void		read_n_c(int fd, t_out *out)//get_name_n_comment
{
	char	*line;
	size_t	n_len;
	size_t	c_len;

	n_len = ft_strlen(NAME_CMD_STRING);
	c_len = ft_strlen(COMMENT_CMD_STRING);
	line = NULL;
	while (!out->c_exist || !out->n_exist)
	{
		while (get_next_line(fd, &line) && (!*line || *line == COMMENT_CHAR))
			ft_memdel((void**)&line);
			//printf("out %d\n", ft_strncmp(COMMENT_CMD_STRING, line, c_len));
		/*	TODO:
			тут две одинаковые проверки
			желательно их как-то объединить.
			Это был первы таск

			Отсутствуют повторные чеки на имя/коммент
			Думаю, что надо, чтобы цикл чекал, чтобы в начале файла были либо пустые строки, либо строки начинающиеся на "."
			Можно обработать и пробелы перед строкой, а то тут через strcmp сравнивается идентичность, а про пробелы вначале ничего
			Надо бы вообще их игнорить, думаю. Но это не точно. Короче именно момент с пробелами спорный, а остальное надо бы сделать.

			Пока что оставляю так как было в оригинале

			Еще в строке с именем\комментом если написать что-то после кавычек - не воспримет как ошибку. Тоже надо исправить
		*/
		if (line && !ft_strncmp(COMMENT_CMD_STRING, line, c_len))
		{
			if (out->c_exist && (g_error.id = 6) && del_str(&line))
				return ;
			read_dotval(fd, out, line + c_len, 1);
		}
		else if (line && !ft_strncmp(NAME_CMD_STRING, line, n_len))
		{
			if (out->n_exist && (g_error.id = 5) && del_str(&line))
				return ;
			read_dotval(fd, out, line + n_len, 0);
		}
		else if (!line && (g_error.id = out->c_exist ? 7 : 8) && del_str(&line))
			return ;
		ft_strdel(&line);
	}
}
