/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:52:05 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/02/03 16:04:36 by immn             ###   ########.fr       */
/*                                                                            */
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
