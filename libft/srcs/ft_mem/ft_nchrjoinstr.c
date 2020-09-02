/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_nchrjoinstr.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/13 13:07:01 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/17 17:16:21 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_nchrjoinstr(char *str, char c, int n)
{
	char	*res;
	int		i;
	int		j;

	if (n < 0)
		return (ft_strdup(str));
	res = ft_strnew(ft_strlen(str) + n);
	j = -1;
	while (n--)
		res[++j] = c;
	i = -1;
	while (str[++i])
		res[++j] = str[i];
	return (res);
}
