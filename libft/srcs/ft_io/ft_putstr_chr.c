/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putstr_chr.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:49:59 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:50:01 by kgarth-o		 ###   ########.fr	   */
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
