/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_colorstr.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/03/13 12:19:01 by aschimme          #+#    #+#             */
/*   Updated: 2020/08/02 08:39:19 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_colorstr(const char *s1, const char *s2, const char *s3)
{
	int i;

	i = 0;
	while (s1[i])
		write(1, &s1[i++], 1);
	i = 0;
	while (s2[i])
		write(1, &s2[i++], 1);
	i = 0;
	while (s3[i])
		write(1, &s3[i++], 1);
}
