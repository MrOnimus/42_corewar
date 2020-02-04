/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_apply_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:52:23 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 12:52:24 by kgarth-o         ###   ########.fr       */
/*                                                                            */
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
