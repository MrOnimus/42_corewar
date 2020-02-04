/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:29:41 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/04/20 19:55:55 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;

	if (!(n = ft_strlen(needle)))
		return ((char*)haystack);
	while (*haystack && len-- >= n)
	{
		if (*haystack == *needle && !(ft_memcmp(haystack, needle, n)))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
