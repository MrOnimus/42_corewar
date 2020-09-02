/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putstr_chr.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/27 03:55:15 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/08/16 07:40:57 by oargrave         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_chr(char const *s, char *c)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen_chr(s, c);
		write(1, s, len);
	}
}
