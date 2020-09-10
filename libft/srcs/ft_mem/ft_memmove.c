/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 16:15:52 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 18:01:22 by rdremora         ###   ########.fr       */
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
