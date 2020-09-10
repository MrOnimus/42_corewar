/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_apply_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 02:32:45 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 18:03:37 by rdremora         ###   ########.fr       */
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
