/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 02:09:36 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 18:31:56 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t t;

	i = 0;
	j = 0;
	t = 0;
	while (s2[t] != '\0')
		t++;
	while (s1[i] != '\0')
		i++;
	if (n > t)
		n = t;
	while (j != n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
