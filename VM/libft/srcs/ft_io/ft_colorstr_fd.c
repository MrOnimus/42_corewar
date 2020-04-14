/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_colorstr_fd.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 12:52:57 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 12:53:00 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_colorstr_fd(const char *s1, const char *s2, const char *s3, int fd)
{
	int i;

	i = 0;
	while (s1[i])
		write(fd, &s1[i++], 1);
	i = 0;
	while (s2[i])
		write(fd, &s2[i++], 1);
	i = 0;
	while (s3[i])
		write(fd, &s3[i++], 1);
}
