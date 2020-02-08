#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_out {
	char		head[4];
	char		name[PROG_NAME_LENGTH];
	char		name_null[4];
	char		code_size[4];
	char		comm[COMMENT_LENGTH];
	char		com_null[4];
	char		*code;
	char		c_exist;
	char		n_exist;
	int			code_size_int;
}				t_out;

typedef struct	s_error {
	char		*filename;
	int			id;
	char		*str_er;
}				t_error;

extern t_error			g_error;

typedef struct	s_t {
	struct s_t	*next;
	char		*mark;
	t_op		*command;
	char		types[3];
	int			values[3];
	char		*a1;
	char		*a2;
	char		*a3;
}				t_tokens;//instructions

typedef	struct	s_m
{
	struct s_m	*next;
	char		*mark;
	size_t		size;
}				t_mark;

char			*correct_name(char *name);
void			say_okey(char *fname);
void			say_error(char *fname);
void			cook_raw(int fd/*, t_out **out, char *filename*/);//translation
void			read_n_c(int fd, t_out *out);//get_name_n_comment
void			del_output(t_out **out);
int				read_code(int fd, t_out *out);

#endif
