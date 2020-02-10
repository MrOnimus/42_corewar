/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_arr.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 12:51:16 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2020/02/03 16:04:31 by immn			 ###   ########.fr	   */
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
