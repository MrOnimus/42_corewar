/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstnew.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/02/20 12:36:15 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/27 19:59:26 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
		{
			return (NULL);
			free(list);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
