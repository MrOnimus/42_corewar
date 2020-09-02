/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 23:58:35 by aschimme          #+#    #+#             */
/*   Updated: 2020/08/26 10:52:07 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long long int n, int base)
{
	char			*hex;
	int				i;
	int				l;
	char			*res;

	if (n == (-9223372036854775807 - 1) && base == 10)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	hex = "0123456789abcdef";
	l = ft_nbrlen_base(ft_abs(n), base) + ((n < 0 && base == 10) ? 1 : 0);
	res = ft_strnew(l);
	(n < 0 && base == 10) ? res[i++] = '-' : (0);
	n < 0 ? n *= -1 : (0);
	while (n)
	{
		res[--l] = hex[n % base];
		n /= base;
	}
	return (res);
}
