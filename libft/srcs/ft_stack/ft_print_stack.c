/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:19:49 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/10 17:47:10 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_stack(t_stk *stack)
{
	while (stack)
	{
		ft_putnbr(stack->num);
		ft_putchar(' ');
		stack = stack->next;
	}
	ft_putchar('\n');
}
