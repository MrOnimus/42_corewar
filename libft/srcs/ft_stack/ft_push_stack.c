/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_push_stack.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/03/05 14:17:53 by oargrave          #+#    #+#             */
/*   Updated: 2020/07/18 00:14:04 by rdremora         ###   ########.fr       */
/*																			*/
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
