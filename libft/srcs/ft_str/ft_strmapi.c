/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:57:28 by aschimme          #+#    #+#             */
/*   Updated: 2020/08/09 10:03:04 by rdremora         ###   ########.fr       */
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
