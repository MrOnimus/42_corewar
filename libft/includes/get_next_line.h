/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 18:24:23 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2020/02/03 16:04:16 by immn			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define MAX_FD 10240

# include "libft.h"

typedef struct		s_files
{
	char			*str;
	int				pos;
	int				end;
	int				fd;
	struct s_files	*next;
}					t_files;

int					get_next_line(const int fd, char **line);
#endif
