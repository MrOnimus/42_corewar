/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/01 14:07:20 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/13 00:25:39 by oargrave         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *box;

	box = (unsigned char*)b;
	while (len--)
		*box++ = (unsigned char)c;
	return (b);
}
