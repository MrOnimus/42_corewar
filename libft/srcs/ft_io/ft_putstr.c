/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putstr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/22 08:53:13 by rdremora          #+#    #+#             */
/*   Updated: 2020/08/21 14:10:17 by oargrave         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		write(1, s + i, 1);
	return (i);
}
