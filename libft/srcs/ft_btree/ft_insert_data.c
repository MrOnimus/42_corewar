/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_insert_data.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 12:51:58 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2020/02/03 16:04:36 by immn			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_data(t_tree **head, void *data, int (*cmp)(void *, void *))
{
	t_tree *node;

	if (!*head)
	{
		*head = ft_create_node(data);
		return ;
	}
	node = *head;
	if (cmp(data, node->data) < 0)
	{
		if (node->left)
			ft_insert_data(&node->left, data, cmp);
		else
			node->left = ft_create_node(data);
	}
	else if (cmp(data, node->data) > 0)
	{
		if (node->right)
			ft_insert_data(&node->right, data, cmp);
		else
			node->right = ft_create_node(data);
	}
}
