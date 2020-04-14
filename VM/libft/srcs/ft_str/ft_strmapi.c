/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:24:57 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/03/23 22:07:04 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str1;
	int		i;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (NULL);
	i = -1;
	if (*s == '\0')
		return (NULL);
	str1 = ft_strnew(ft_strlen(s));
	if (!str1)
		return (NULL);
	while (*(s + ++i))
		*(str1 + i) = f(i, *(s + i));
	return (str1);
}
