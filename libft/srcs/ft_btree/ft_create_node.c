/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_create_node.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/03/11 02:02:46 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/13 11:54:21 by aschimme         ###   ########.fr       */
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
