/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/04 13:10:57 by immn			  #+#	#+#			 */
/*   Updated: 2020/02/04 13:31:22 by immn			 ###   ########.fr	   */
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
		else if (!(file_name = correct_name(*av)))
		{
			g_error.id = 2;
			close(fd);
		}
		else
		{
			cook_raw(fd, &out, file_name);
			close(fd);
		}
		if (g_error.id)
			say_error(file_name);
		else
			say_okey(file_name);
	}
	return (0);
}
