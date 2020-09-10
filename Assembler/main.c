/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 22:42:35 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 18:26:59 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		message(int id, char *file_name)
{
	if (id)
		fail_msg(file_name);
	else
		success_msg(file_name);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*file_name;
	t_out	*out;

	file_name = NULL;
	while (--ac)
	{
		g_error.filename = *(++av);
		fd = open(*av, O_RDONLY);
		if (fd < 3)
			g_error.id = 1;
		else if (!(file_name = check_valid_name(*av)))
		{
			g_error.id = 2;
			close(fd);
		}
		else
		{
			translation(fd, &out, file_name);
			close(fd);
		}
		message(g_error.id, file_name);
	}
	return (0);
}
