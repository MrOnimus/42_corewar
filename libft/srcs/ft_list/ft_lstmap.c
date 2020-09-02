/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstmap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/05/08 04:53:36 by aschimme          #+#    #+#             */
/*   Updated: 2020/08/29 14:47:07 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_lstmap_del(t_list *r)
{
	t_list		*t;

	while (r)
	{
		t = r;
		r = r->next;
		if (t->content)
			free(t->content);
		free(t);
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (!lst)
		return (NULL);
	if (f == NULL)
		return (NULL);
	if (!(list = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	new = list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(list->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			ft_lstmap_del(lst);
		list = list->next;
	}
	return (new);
}
