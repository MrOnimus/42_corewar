/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:36:34 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/04/20 19:27:15 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (haystack[i] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return ((char*)&haystack[k]);
				j++;
				i++;
			}
			i = k;
		}
		i++;
	}
	return (0);
}
