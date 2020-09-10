/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 20:33:07 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/10 18:31:56 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		flag;
	char	*c;
	int		i;

	i = 0;
	c = ft_strnew(ft_countchars(n));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (c == NULL)
		return (NULL);
	flag = (n < 0) ? -1 : 0;
	n = (flag < 0) ? n * -1 : n;
	if (n == 0)
		c[i++] = '0';
	while (n > 0)
	{
		c[i++] = '0' + n % 10;
		n = n / 10;
	}
	if (flag < 0)
		c[i++] = '-';
	ft_strrev(c);
	return (c);
}
