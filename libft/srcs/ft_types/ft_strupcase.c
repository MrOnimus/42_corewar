/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strupcase.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <kgarth-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 13:56:48 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2019/10/29 13:56:48 by kgarth-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char *tmp;

	tmp = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 'a' + 'A';
		str++;
	}
	return (tmp);
}