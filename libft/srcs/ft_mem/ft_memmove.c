/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 00:44:23 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/04/07 18:43:20 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *c0;
	char *c1;

	if (dst == NULL && src == NULL)
		return (NULL);
	c0 = (char*)dst;
	c1 = (char*)src;
	if (c1 < c0)
	{
		c1 = c1 + len - 1;
		c0 = c0 + len - 1;
		while (len > 0)
		{
			*c0-- = *c1--;
			len--;
		}
	}
	else
		while (len-- > 0)
			*c0++ = *c1++;
	return (dst);
}
