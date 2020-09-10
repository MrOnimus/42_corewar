/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_wh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:01:14 by oargrave          #+#    #+#             */
/*   Updated: 2020/09/10 18:05:40 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_wh(char *s, char c)
{
	int	len;

	len = ft_strnchr(s, c, 1);
	if (len == -1)
		return (ft_putstr(s));
	else
		write(1, s, len);
	return (len);
}
