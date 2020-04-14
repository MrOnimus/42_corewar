/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstdelone.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/02/21 19:16:13 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/04/07 00:00:46 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	return ;
}
