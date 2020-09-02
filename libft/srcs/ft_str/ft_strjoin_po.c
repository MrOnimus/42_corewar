/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_po.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:58:23 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/01 13:29:35 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_po(char const *s1, char const *s2)
{
	char	*concat;
	size_t	i;
	size_t	j;

	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	concat = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (concat == NULL)
		return (NULL);
	i = ft_strlen(s1);
	while (*s1)
		*(concat + j++) = *s1++;
	while (*s2)
		*(concat + i++) = *s2++;
	*(concat + i) = '\n';
	return (concat);
}
