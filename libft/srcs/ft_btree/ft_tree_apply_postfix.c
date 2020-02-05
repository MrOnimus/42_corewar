/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tree_apply_postfix.c							:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 12:52:16 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2020/02/03 16:04:37 by immn			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_apply_postfix(t_tree *head, void (*applyf)(void *))
{
	if (!head)
		return ;
	ft_tree_apply_postfix(head->left, applyf);
	ft_tree_apply_postfix(head->right, applyf);
	(applyf)(head->data);
}
