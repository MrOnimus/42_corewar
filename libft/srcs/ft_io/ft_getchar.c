/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_getchar.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 12:53:17 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 12:55:24 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		ft_getchar(void)
{
	static char	buf[BUFF_SIZE];
	static char	*bufp = buf;
	static int	n = 0;

	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
