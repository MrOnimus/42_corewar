/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/05/26 22:42:35 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/11 20:19:17 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "asm.h"

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
		if (g_error.id)
			fail_msg(file_name);
		else
			success_msg(file_name);
	}
	return (0);
}
