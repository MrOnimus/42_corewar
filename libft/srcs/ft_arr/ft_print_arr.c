/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:32:21 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 17:34:13 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("arr[%d] = %d\n", i, array[i]);
		i++;
	}
}
