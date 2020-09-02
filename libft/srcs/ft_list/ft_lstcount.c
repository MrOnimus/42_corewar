/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstcount.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/14 16:38:34 by aschimme          #+#    #+#             */
/*   Updated: 2020/07/08 13:28:03 by aschimme         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcount(t_list *lst)
{
	size_t i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
