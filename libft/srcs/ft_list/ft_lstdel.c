/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstdel.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/01 09:24:43 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/26 03:46:33 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (!del)
		while (*alst)
		{
			if (next)
				free(next->content);
			next = (*alst)->next;
			free(*alst);
			*alst = next;
		}
	else
		while (*alst)
		{
			if (next)
				free(next->content);
			next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = next;
		}
}
