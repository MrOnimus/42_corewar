/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_stack_isempty.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:52:28 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:52:29 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int		ft_stack_isempty(t_stk *stack)
{
	if (stack == NULL)
		return (1);
	else
		return (0);
}
