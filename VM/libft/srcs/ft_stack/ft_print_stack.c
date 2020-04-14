/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_stack.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:52:18 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:52:19 by kgarth-o		 ###   ########.fr	   */
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
