/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:55:15 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 18:02:57 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_chr(char const *s, char *c)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen_chr(s, c);
		write(1, s, len);
	}
}
