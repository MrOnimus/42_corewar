/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 12:48:30 by oargrave          #+#    #+#             */
/*   Updated: 2020/07/24 18:18:18 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen_chr(const char *s, char *c)
{
	const char *tmp;

	tmp = s;
	while (*tmp && tmp != c)
		++tmp;
	return (tmp - s);
}
