/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tree_apply_postfix.c							:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/03 06:15:58 by oargrave          #+#    #+#             */
/*   Updated: 2020/08/24 04:24:40 by kgarth-o         ###   ########.fr       */
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
