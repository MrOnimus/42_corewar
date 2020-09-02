/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:26:55 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/03 20:31:12 by aschimme         ###   ########.fr       */
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
