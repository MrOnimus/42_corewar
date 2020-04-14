/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_pop_stack.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:52:13 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:52:14 by kgarth-o		 ###   ########.fr	   */
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
