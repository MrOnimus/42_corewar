/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstlen.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/09 02:54:00 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/30 17:01:30 by aschimme         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int			ft_lstlen(t_list *head)
{
	t_list	*temp;
	int		len;

	temp = head;
	len = 0;
	while (temp)
	{
		len += 1;
		temp = temp->next;
	}
	return (len);
}
