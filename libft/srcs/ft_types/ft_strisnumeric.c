/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strisnumeric.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:56:26 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:56:27 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_strisnumeric(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9'))
			return (0);
	}
	return (1);
}
