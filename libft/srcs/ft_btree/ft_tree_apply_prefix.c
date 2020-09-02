/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tree_apply_prefix.c							 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/03 02:32:45 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/08/09 20:31:34 by oargrave         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_apply_prefix(t_tree *head, void (*applyf)(void *))
{
	if (!head)
		return ;
	(applyf)(head->data);
	ft_tree_apply_prefix(head->left, applyf);
	ft_tree_apply_prefix(head->right, applyf);
}
