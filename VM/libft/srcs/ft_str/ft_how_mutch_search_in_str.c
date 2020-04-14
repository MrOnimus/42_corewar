/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_mutch_search_in_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:49:29 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/09/28 18:43:39 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_how_mutch_search_in_str(char *str, char *search)
{
	char	*temp;
	size_t	len_search;
	int		nb_occur;

	temp = str;
	len_search = 0;
	nb_occur = 0;
	if (search == NULL)
		return (0);
	else
		len_search = ft_strlen(search);
	while (str)
	{
		if ((str = ft_strstr(str, search)))
		{
			nb_occur++;
			str = str + len_search;
		}
	}
	return (nb_occur);
}
