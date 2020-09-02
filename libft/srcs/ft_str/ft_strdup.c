/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 01:42:43 by oargrave          #+#    #+#             */
/*   Updated: 2020/08/03 08:04:29 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_secure(const char *s)
{
	if (s == NULL)
		return (0);
	else
		return (ft_strlen(s));
}

char			*ft_strdup(const char *s1)
{
	char		*duplicate;
	int			strlen;
	int			j;

	strlen = ft_strlen_secure(s1);
	j = 0;
	duplicate = (char *)malloc(((unsigned long)strlen + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		duplicate[j] = s1[j];
		j++;
	}
	duplicate[j] = '\0';
	return (duplicate);
}
