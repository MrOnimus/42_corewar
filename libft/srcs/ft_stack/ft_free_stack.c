/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_free_stack.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/10 06:45:59 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/08/14 22:29:02 by rdremora         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_free_stack(t_stk *stack)
{
	t_stk *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	stack = NULL;
}
