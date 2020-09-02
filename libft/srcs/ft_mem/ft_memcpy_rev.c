/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:28:01 by aschimme          #+#    #+#             */
/*   Updated: 2020/07/22 04:38:57 by aschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	unsigned char	*new;
	unsigned char	*from;

	new = (unsigned char*)dst;
	from = (unsigned char*)src;
	while (n-- > 0)
		*(new++) = from[n];
	return (dst);
}
