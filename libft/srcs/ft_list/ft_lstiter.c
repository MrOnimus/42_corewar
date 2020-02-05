/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstiter.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/02/21 22:28:52 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/04/07 18:48:38 by kgarth-o		 ###   ########.fr	   */
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
