/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:08:35 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/03/23 22:06:07 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_strrev(char *a)
{
	int		len;
	int		i;
	char	buf;

	i = 0;
	len = ft_strlen(a) - 1;
	if (len == 0)
		return (*a);
	while (i < len)
	{
		buf = a[i];
		a[i] = a[len];
		a[len] = buf;
		i++;
		len--;
	}
	return (*a);
}
