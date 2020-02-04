/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:47:38 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/04/19 20:03:21 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*c;
	const char	*c1;

	if (dst == src)
		return (dst);
	c = dst;
	c1 = src;
	while (n > 0)
	{
		*c++ = *c1++;
		n--;
	}
	return (dst);
}
