/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_roundd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:55:38 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:55:40 by kgarth-o         ###   ########.fr       */
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
