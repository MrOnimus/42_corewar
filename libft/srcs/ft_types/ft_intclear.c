/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_intclear.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/06 18:47:25 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/04/06 22:40:08 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static char	ft_josk(int i, int j, char t)
{
	if (i == 1)
	{
		if (j > 0)
			return ('+');
		else
			return ('-');
	}
	return (t);
}

char		*ft_intclear(const char *str, int i, int j)
{
	int		c[3];
	char	*clear;

	while (*(str + i) == '\n' || *(str + i) == '\t' ||
		*(str + i) == '\r' || *(str + i) == '\v' ||
		*(str + i) == '\f' || *(str + i) == ' ')
		i++;
	c[0] = (*(str + i) == '-' || *(str + i) == '+') ? 1 : 0;
	c[1] = ((c[0] == 1) && (*(str + i)) == '+') ? 1 : 0;
	c[1] = ((c[0] == 1) && (*(str + i)) == '-') ? -1 : c[1];
	i = (*(str + i) == '-' || *(str + i) == '+') ? i + 1 : i;
	i = i < 0 ? 0 : i;
	c[2] = ft_strlen(str);
	while (i++ <= c[2])
		if (*(str + i) <= '9' && *(str + i) >= '0')
			j++;
		else
			break ;
	clear = ft_strnew(j + c[0]);
	clear[0] = ft_josk(c[0], c[1], clear[0]);
	i -= j + 1;
	j = j + 2;
	while (j--)
		clear[c[0]++] = str[i++];
	return (clear);
}
