/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/28 04:55:28 by oargrave          #+#    #+#             */
/*   Updated: 2020/08/26 06:31:30 by kgarth-o         ###   ########.fr       */
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
