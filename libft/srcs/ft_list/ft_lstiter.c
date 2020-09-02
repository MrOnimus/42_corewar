/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstiter.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/03/18 18:02:36 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/29 20:32:10 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || f == NULL)
		return ;
	if (lst->next)
		ft_lstiter(lst->next, f);
	f(lst);
}
