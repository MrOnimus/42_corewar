/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstlen.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rdremora <rdremora@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/28 00:08:42 by rdremora		  #+#	#+#			 */
/*   Updated: 2019/10/28 00:08:51 by rdremora		 ###   ########.fr	   */
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
