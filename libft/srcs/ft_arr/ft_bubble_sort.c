/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_bubble_sort.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/03 03:39:24 by aschimme          #+#    #+#             */
/*   Updated: 2020/07/21 15:33:22 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void			ft_bubble_sort(int *arr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
