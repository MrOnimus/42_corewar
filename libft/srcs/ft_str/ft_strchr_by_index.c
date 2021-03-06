/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_by_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:52:47 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:52:48 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_by_index(char *str, int c)
{
	int j;

	j = 0;
	while (str[j])
	{
		if (str[j] == c)
			return (j);
		j++;
	}
	return (-1);
}
