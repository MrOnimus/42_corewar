/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:53:28 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:53:30 by kgarth-o         ###   ########.fr       */
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
