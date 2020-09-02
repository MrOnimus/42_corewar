/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strislowercase.c								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/18 01:01:07 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/26 16:54:04 by rdremora         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_strislowercase(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_islower(*str++))
			return (0);
	return (1);
}
