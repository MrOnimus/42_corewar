/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_free_stack.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:52:07 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:52:09 by kgarth-o		 ###   ########.fr	   */
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
