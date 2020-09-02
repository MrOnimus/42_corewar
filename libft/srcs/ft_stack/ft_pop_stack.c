/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_pop_stack.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/07 02:39:57 by oargrave          #+#    #+#             */
/*   Updated: 2020/07/14 10:55:39 by rdremora         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int		ft_pop_stack(t_stk **stack)
{
	t_stk	*tmp;
	int		i;

	if (stack == NULL)
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	i = tmp->num;
	tmp->next = NULL;
	free(tmp);
	return (i);
}
