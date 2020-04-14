/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:58:17 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/04/07 18:47:51 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	if (s && f)
		while (*(s + i))
		{
			f(i, s + i);
			i++;
		}
}
