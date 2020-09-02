/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_flagclear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:11:21 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/30 09:06:50 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_flag(char *s1, int free1, char *s2, int free2)
{
	char	*temp1;
	char	*temp2;
	char	*mew;

	temp1 = s1;
	temp2 = s2;
	mew = ft_strjoin(s1, s2);
	if (free1 == 1)
		free(temp1);
	if (free2 == 1)
		free(temp2);
	return (mew);
}
