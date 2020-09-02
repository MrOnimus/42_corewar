/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 11:54:10 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:39 by aschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumeric(char *str)
{
	size_t	tmp;

	tmp = 0;
	while ((int)str[tmp])
	{
		if (!ft_isdigit(str[tmp]))
			return (0);
		tmp++;
	}
	return (1);
}
