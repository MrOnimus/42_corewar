/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_chjoinstr.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/23 05:03:30 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/09/01 09:02:32 by oargrave         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_chjoinstr(char c, char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	if (c == '\0')
		return (ft_strdup(str));
	res = ft_strnew(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = 0;
	res[0] = c;
	while (str[i])
	{
		res[i + 1] = str[i];
		i++;
	}
	return (res);
}
