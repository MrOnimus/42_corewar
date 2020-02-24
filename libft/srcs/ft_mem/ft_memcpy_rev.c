/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:35:34 by immn              #+#    #+#             */
/*   Updated: 2020/02/24 16:36:56 by immn             ###   ########.fr       */
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
