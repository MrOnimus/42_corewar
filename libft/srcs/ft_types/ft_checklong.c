/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_checklong.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/26 10:59:36 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/20 18:25:59 by rdremora         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int		ft_checklong(const char *str)
{
	int i;

	i = ft_strlen(str);
	if (i >= 19)
	{
		if (i == 19)
		{
			if (ft_strcmp(str, "9223372036854775807") > 0)
				return (-1);
		}
		else if ((i == 20) && (*str == '-'))
		{
			if (ft_strcmp(str, "-9223372036854775808") > 0)
				return (1);
		}
		else
		{
			if (*str == '-')
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}
