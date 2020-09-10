/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:17:31 by oargrave          #+#    #+#             */
/*   Updated: 2020/09/10 17:57:48 by rdremora         ###   ########.fr       */
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
