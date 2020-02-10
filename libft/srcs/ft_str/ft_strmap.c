/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:24:20 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/04/07 18:52:14 by kgarth-o         ###   ########.fr       */
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
