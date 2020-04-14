/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putstr_wh.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/14 17:12:18 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:28:15 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_wh(char *s, char c)
{
	int	len;

	len = ft_strnchr(s, c, 1);
	if (len == -1)
		return (ft_putstr(s));
	else
		write(1, s, len);
	return (len);
}
