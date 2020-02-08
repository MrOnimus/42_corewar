/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_colorstr.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 12:53:13 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 12:53:14 by kgarth-o		 ###   ########.fr	   */
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
