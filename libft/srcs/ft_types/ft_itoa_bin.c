/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 06:28:27 by oargrave          #+#    #+#             */
/*   Updated: 2020/08/01 19:05:07 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_pow(int n)
{
	int		i;

	if (n % 2 != 0)
		return (-1);
	i = 0;
	while (n != 1)
	{
		n /= 2;
		++i;
	}
	return (i);
}

static int	get_mask(int bits)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	while (++i < bits)
		k = k | (k << 1);
	return (k);
}

char		*ft_itoa_bin(unsigned long value, int base, int i)
{
	char	*str[2];
	int		bits;
	int		shift;
	int		tmp;
	int		flag;

	if ((bits = get_pow(base)) == -1)
		return (NULL);
	shift = ((bits != 3) ? 64 / bits - 1 : 64 / bits);
	flag = 0;
	if (!(str[1] = ft_strnew(1)))
		return (NULL);
	while (shift >= 0)
	{
		str[0] = str[1];
		tmp = (value >> (shift * bits)) & get_mask(bits);
		if (!flag && shift && tmp == 0 && shift--)
			continue ;
		flag = 1;
		if (!(str[1] = ft_strjoin_free(str[0], ft_itoa_base(tmp, base, i), 3)))
			return (NULL);
		--shift;
	}
	return (str[1]);
}
