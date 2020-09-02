/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:32:41 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/27 19:12:37 by kgarth-o         ###   ########.fr       */
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
