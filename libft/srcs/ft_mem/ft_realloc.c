/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_realloc.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/20 03:35:35 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/07/25 03:24:38 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void *new;

	if (!ptr)
		return (NULL);
	if (!(new = malloc(new_size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, prev_size < new_size ? prev_size : new_size);
	free(ptr);
	return (new);
}
