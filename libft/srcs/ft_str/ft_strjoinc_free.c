/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:53:22 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:53:24 by kgarth-o         ###   ########.fr       */
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
