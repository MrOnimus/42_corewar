/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_checklong.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/03/23 20:44:52 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/03/23 21:44:57 by kgarth-o		 ###   ########.fr	   */
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
