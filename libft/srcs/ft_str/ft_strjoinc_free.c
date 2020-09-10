/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:56:30 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/10 18:31:56 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinc_free(const char *a, char b, int cl)
{
	char	*s;
	int		len;

	len = (a ? ft_strlen(a) : 0);
	if (!(s = ft_strnew(len + 1)))
		return (NULL);
	if (a)
		ft_strcat(s, a);
	s[len] = b;
	if (cl == 1)
		free((char *)a);
	return (s);
}
