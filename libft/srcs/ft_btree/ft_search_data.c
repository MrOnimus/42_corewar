/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_search_data.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/09 19:13:53 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/08/24 08:17:26 by oargrave         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_search_data(t_tree *head, void *data, int (*cmp)(void *, void *))
{
	void *out;

	out = NULL;
	if (head)
	{
		out = ft_search_data(head->left, data, cmp);
		if (!out && (!(*cmp)(head->data, data)))
			out = head->data;
		if (!out)
			out = ft_search_data(head->right, data, cmp);
	}
	return (head);
}
