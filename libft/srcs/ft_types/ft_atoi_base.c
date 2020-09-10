/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:38:09 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 17:48:05 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_correct(char c, int base)
{
	if (base < 2 || base > 16)
		return (0);
	if (c >= '0' && c <= '9')
	{
		if (c - '0' > base)
			return (0);
	}
	else if (c >= 'a' && c <= 'z')
	{
		if (c - 'a' > base - 10)
			return (0);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		if (c - 'A' > base - 10)
			return (0);
	}
	return (1);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int				i;
	int				sign;
	unsigned int	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	(str[i] == '-' || str[i] == '+') ? i++ : 0;
	while (is_correct(str[i], str_base))
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * str_base + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f' && str_base > 10)
			num = num * str_base + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F' && str_base > 10)
			num = num * str_base + str[i] - 'a' + 10;
		else
			return (num);
		i++;
	}
	return (sign * num);
}
