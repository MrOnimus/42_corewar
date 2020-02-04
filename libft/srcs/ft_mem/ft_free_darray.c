/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:50:38 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 20:05:50 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_darray(char **args)
{
	int i;

	i = -1;
	while (++i < ft_count_words(args))
		free(args[i]);
	free(args);
	return (1);
}
