/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_roundd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:22:32 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/10 12:45:39 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long	ft_itoa_round(double tmp)
{
	int		sign;

	sign = 1;
	if (tmp < 0)
	{
		tmp = -tmp;
		sign = -1;
	}
	if ((long)(tmp * 10) - (long)tmp * 10 >= 5)
		return (((long)(tmp) + 1) * sign);
	return ((long)tmp * sign);
}
