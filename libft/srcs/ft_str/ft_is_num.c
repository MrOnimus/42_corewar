/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:12:02 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 17:44:46 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_is_num(char *s)
{
	if (*s == '-' || ft_isdigit(*s))
	{
		if (ft_res_is_true(s + 1, ft_isdigit))
			return (1);
		return (0);
	}
	return (0);
}
