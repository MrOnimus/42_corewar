/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstdel.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/02/21 20:25:10 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:17:43 by kgarth-o		 ###   ########.fr	   */
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
