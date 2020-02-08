/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_toupper.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/01/27 19:23:07 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:56:54 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 'a' + 'A');
	else
		return (c);
}