/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memcpy.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/03/15 04:06:59 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/09/02 07:51:17 by rdremora         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*c;
	const char	*c1;

	if (dst == src)
		return (dst);
	c = dst;
	c1 = src;
	while (n > 0)
	{
		*c++ = *c1++;
		n--;
	}
	return (dst);
}
