/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:27:46 by aschimme          #+#    #+#             */
/*   Updated: 2020/08/05 23:48:20 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_len(unsigned long n)
{
	int		len;

	len = 1;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa_u(unsigned long n)
{
	char	*str;
	int		len;

	len = get_len(n);
	if ((str = (char*)malloc(sizeof(char) * len + 1)))
	{
		str[len] = '\0';
		while (len--)
		{
			str[len] = '0' + n % 10;
			n = n / 10;
		}
		return (str);
	}
	return (NULL);
}
