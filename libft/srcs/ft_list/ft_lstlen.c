/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 02:54:00 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 17:56:31 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstlen(t_list *head)
{
	t_list	*temp;
	int		len;

	temp = head;
	len = 0;
	while (temp)
	{
		len += 1;
		temp = temp->next;
	}
	return (len);
}
