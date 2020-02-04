/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 23:06:48 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/04/19 21:25:45 by kgarth-o         ###   ########.fr       */
/*                                                                            */
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
