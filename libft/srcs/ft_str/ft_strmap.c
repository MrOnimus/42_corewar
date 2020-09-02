/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 13:34:52 by oargrave          #+#    #+#             */
/*   Updated: 2020/07/24 01:06:18 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		*(str1 + i) = f(*(s + i));
	return (str1);
}
