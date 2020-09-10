/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:20:11 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/10 18:04:15 by rdremora         ###   ########.fr       */
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
