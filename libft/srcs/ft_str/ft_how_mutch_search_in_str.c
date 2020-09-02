/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_mutch_search_in_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:51:57 by rdremora          #+#    #+#             */
/*   Updated: 2020/08/28 19:30:42 by kgarth-o         ###   ########.fr       */
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
