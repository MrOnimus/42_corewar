/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_swap.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:51:00 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:51:02 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}
