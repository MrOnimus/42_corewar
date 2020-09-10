/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 06:29:24 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/10 17:48:16 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa_pointer(void *p)
{
	char	*buff2;
	char	*str;
	long	shift;
	long	tmp;
	int		flag;

	shift = 15;
	flag = 0;
	if (!(str = ft_strnew(1)))
		return (NULL);
	while (shift >= 0)
	{
		tmp = ((long)p >> (shift * 4)) & 15;
		if (!flag && shift != 1 && tmp == 0 && shift--)
			continue ;
		else
			flag = 1;
		if (!(buff2 = ft_itoa_base(tmp, 16, 0)))
			return (NULL);
		if (!(str = ft_strjoin_free(str, buff2, 3)))
			return (NULL);
		--shift;
	}
	return (str);
}
