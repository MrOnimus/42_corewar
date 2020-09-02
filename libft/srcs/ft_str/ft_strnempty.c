/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strempty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 22:30:17 by aschimme          #+#    #+#             */
/*   Updated: 2020/08/01 17:04:19 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnempty(char *s, size_t n)
{
	while (n > 0)
	{
		if (*s != '\t' && *s != ' ')
			return (0);
		s++;
		n--;
	}
	return (1);
}
