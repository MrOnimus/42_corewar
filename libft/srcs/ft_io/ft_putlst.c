/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 00:12:00 by rdremora          #+#    #+#             */
/*   Updated: 2019/10/28 00:12:02 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlst(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		if (temp->content)
		{
			ft_putstr((char *)temp->content);
			ft_putchar('\n');
		}
		temp = temp->next;
	}
}
