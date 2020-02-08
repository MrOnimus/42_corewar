/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_create_node.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 12:51:46 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2020/02/03 16:04:34 by immn			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_create_node(void *data)
{
	t_tree	*node;

	if (!(node = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	if (node)
	{
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}
