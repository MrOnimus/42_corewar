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

t_mark			*fill_mark(t_tokens *read, char status);
t_tokens		*del_empty(t_tokens *read);
t_tokens		*parse_line(char *line);
void			*free_return(t_tokens *new);
char			*check_valid_name(char *name);
t_op			*cmp_commands(char *l, size_t pos);
size_t			weight(t_tokens *me);
void			add_tok(t_tokens **toks, t_tokens **curr, t_tokens *new);
char			free_two_dim_array(char **me);
void			success_msg(char *fname);
void			get_name_n_comment(int fd, t_out *out);
char			find_sep(char *l, size_t *p);
void			translation(int fd, t_out **out, char *filename);
void			del_marks(t_mark *me);
void			fail_msg(char *fname);
int				read_instructions(int fd, t_out *out);
char			check_arg(char **arg, char *type, int *value);
int				mark_position(char *name, t_mark *marks);
void			del_output(t_out **out);
void			del_tokens(t_tokens *me);
char			parse_args(char *line, t_tokens *new);
void			free_bad_args(t_tokens *new, int n_arg, char **args);
char			label_correct(char *l);
size_t			move_marks(t_tokens *read, t_mark *mark);
void			skip_emptyness(char **p);
int				check_for_comment(char *line);
void			crop_comment(char *line);
void			code_to_bytes(t_tokens *tokens, t_out *out);



#endif
