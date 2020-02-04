/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:52:23 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:52:24 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_stack(t_stk **stack, int num)
{
	t_stk *temp;

	if (stack == NULL)
	{
		*stack = (t_stk *)malloc(sizeof(t_stk));
		(*stack)->next = NULL;
		(*stack)->num = num;
	}
	else
	{
		temp = (t_stk *)malloc(sizeof(t_stk));
		temp->next = *stack;
		temp->num = num;
		*stack = temp;
	}
}
