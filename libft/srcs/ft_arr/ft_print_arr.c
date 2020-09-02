/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_arr.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/29 10:40:53 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/24 12:06:38 by oargrave         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("arr[%d] = %d\n", i, array[i]);
		i++;
	}
}
