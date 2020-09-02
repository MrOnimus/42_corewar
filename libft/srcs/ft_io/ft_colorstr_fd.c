/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_colorstr_fd.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/03/19 09:59:32 by oargrave          #+#    #+#             */
/*   Updated: 2020/07/26 12:39:24 by rdremora         ###   ########.fr       */
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
