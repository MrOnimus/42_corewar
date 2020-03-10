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

void	del_3_str(char **s1, char **s2, char **s3) // TODO: От этого костыля стопроц надо избавляться, надо придумать что-то красивое
{
	if (s1)
		ft_strdel(s1);
	if (s2)
		ft_strdel(s2);
	if (s3)
		ft_strdel(s3);
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

static void	read_name(int fd, t_out *out, char *line)//read_name_n_com
{
	char	*start;
	char	*name;
	char	*tmp;

	tmp = NULL;
	if ((!(start = ft_strchr(line, '"')) || !is_empty(line, start - line))
		&& (g_error.id = 4))
		return ;
	if ((name = give_full_name(fd, COMMENT_LENGTH, start + 1, tmp)))
	{
		ft_strcpy(out->comm, name);
		ft_strdel(&name);
	}
	else
		g_error.id += 1;
	out->n_exist = 1;
}

static void	read_comment(int fd, t_out *out, char *line)
{
	char	*start;
	char	*name;
	char	*tmp;

	tmp = NULL;
	if ((!(start = ft_strchr(line, '"')) || !is_empty(line, start - line))
		&& (g_error.id = 4))
		return ;
	if ((name = give_full_name(fd, COMMENT_LENGTH, start + 1, tmp)))
	{
		ft_strcpy(out->comm, name);
		ft_strdel(&name);
	}
	else
		g_error.id += 1;
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
			плюс функци read_comment и read_name сделать одной функцией с до параметром
			а то нахер нужны две функции, которые только захардкоженными элементами отличаются

			Это был первы таск

			Второй таск - основной цикл из этой функции (while (!out->c_exist || !out->n_exist))
			как бы не очень работает
			Если мы сначала зададим имя, а потом коммент, или наоборот, то цикл сразу закончится
			При этом потом можно будет задать имя еще раз и коммент тоже - никаких проверок об этом уже не будет

			Думаю, что надо, чтобы цикл чекал, чтобы в начале файла были либо пустые строки, либо строки начинающиеся на "."
			Можно обработать и пробелы перед строкой, а то тут через strcmp сравнивается идентичность, а про пробелы вначале ничего
			Надо бы вообще их игнорить, думаю. Но это не точно. Короче именно момент с пробелами спорный, а остальное надо бы сделать.


			Пока что оставляю так как было в оригинале


			Еще надо, чтобы писало не о первой попавшейся ошибке, а об обеих
			Типа если дублируется и имя и коммент, то чтобы писало и о первом и о втором

			Еще в строке с именем\комментом если написать что-то после кавычек - не воспримет как ошибку. Тоже надо исправить
		*/
		if (line && !ft_strncmp(COMMENT_CMD_STRING, line, c_len))
		{
			if (out->c_exist && (g_error.id = 6) && del_str(&line))
				return ;
			read_comment(fd, out, line + c_len);
		}
		else if (line && !ft_strncmp(NAME_CMD_STRING, line, n_len))
		{
			if (out->n_exist && (g_error.id = 5) && del_str(&line))
				return ;
			read_name(fd, out, line + n_len);
		}
		else if (!line && (g_error.id = out->c_exist ? 7 : 8) && del_str(&line))
			return ;
		ft_strdel(&line);
	}
}
