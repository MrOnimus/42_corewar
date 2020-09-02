/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_stack.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/22 12:19:49 by aschimme          #+#    #+#             */
/*   Updated: 2020/08/13 21:10:18 by aschimme         ###   ########.fr       */
/*																			*/
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
