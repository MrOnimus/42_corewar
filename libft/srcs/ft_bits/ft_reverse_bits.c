/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_reverse_bits.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/04/26 02:07:39 by kgarth-o          #+#    #+#             */
/*   Updated: 2020/09/05 15:17:18 by kgarth-o         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

unsigned int	ft_reverse_bits(int octet)
{
	return (((octet >> 0) & 1) << 7) |\
	(((octet >> 1) & 1) << 6) |\
	(((octet >> 2) & 1) << 5) |\
	(((octet >> 3) & 1) << 4) |\
	(((octet >> 4) & 1) << 3) |\
	(((octet >> 5) & 1) << 2) |\
	(((octet >> 6) & 1) << 1) |\
	(((octet >> 7) & 1) << 0);
}
