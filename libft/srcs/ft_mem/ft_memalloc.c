/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memalloc.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/07 11:41:39 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/30 14:48:48 by aschimme         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	if (size == 0)
		return (NULL);
	memory = malloc(size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
