/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:54:03 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:54:04 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	n;
	int		isneg;

	isneg = 0;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		isneg = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (isneg)
		return (-n);
	else
		return (n);
}
