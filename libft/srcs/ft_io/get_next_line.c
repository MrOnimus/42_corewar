/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 11:39:24 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 17:55:28 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_len(char **s, int length, int fd)
{
	while (s[fd][length] != '\n' && s[fd][length] != '\0')
		length++;
	return (length);
}

static int		ft_makeline(char **s, char **line, int fd, int ret)
{
	int			length;
	char		*tmp;

	length = ft_len(s, 0, fd);
	if (s[fd][length] == '\n')
	{
		if (!(*line = ft_strsub(s[fd], 0, length)))
			return (-1);
		if (!(tmp = ft_strdup(s[fd] + length + 1)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][length] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		if (!(*line = ft_strdup(s[fd])))
			return (-1);
		ft_strdel((&s[fd]));
	}
	return (1);
}

static int		ft_gnl_cycle(const int fd, char **s)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		(s[fd] == NULL) && (s[fd] = ft_strnew(0));
		if (!s)
			return (-1);
		buffer[ret] = '\0';
		if (!(tmp = ft_strjoin(s[fd], buffer)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	ret = ft_gnl_cycle(fd, s);
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	return (ft_makeline(s, line, fd, ret));
}
