/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   02.c											   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/02/04 13:12:27 by immn			  #+#	#+#			 */
/*   Updated: 2020/02/04 13:16:01 by immn			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "asm.h"

char	*correct_name(char *name)//check_valid_name
{
	char *p;
	char *tmp;
	char *new;

	p = ft_strstr(name, ".s");
	if (!p || *(p + 2))
		return (NULL);
	tmp = ft_strsub(name, 0, p - name);
	new = ft_strjoin(tmp, ".cor");
	free(tmp);
	return (new);
}

void	say_okey(char *fname)//success_msg
{
	ft_putstr_fd("\033[0;32mThe file : \033[0m", 1);
	ft_putstr_fd(g_error.filename, 1);
	ft_putstr_fd(" \033[32m ...Writing output to: \033[0m", 1);
	ft_putendl_fd(fname, 1);
	ft_strdel(&fname);
	g_error.id = 0;
	g_error.str_er = NULL;
}
