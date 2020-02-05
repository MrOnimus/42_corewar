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

// typedef struct	s_t {
// 	struct s_t	*next;
// 	char		*mark;
// 	t_op		*command;
// 	char		types[3];
// 	int			values[3];
// 	char		*a1;
// 	char		*a2;
// 	char		*a3;
// }				t_tokens;

// typedef	struct	s_m
// {
// 	struct s_m	*next;
// 	char		*mark;
// 	size_t		size;
// }				t_mark;

char			*correct_name(char *name);
void			say_okey(char *fname);
void			say_error(char *fname);

// char			parse_args(char *line, t_tokens *new_line);
// char			check_arg(char **arg, char *type, int *value);

// size_t			weight(t_tokens *me);

// void			read_n_c(int fd, t_out *out);
// int				read_code(int fd, t_out *out);
// t_tokens		*validate(int fd);
// void			cook_raw(int fd, t_out **out, char *filename);

// int				empty(char *s, size_t n);
// void			skip_emptyness(char **p);
// void			del_marks(t_mark *me);
// void			del_output(t_out **out);
// void			del_tokens(t_tokens *me);
// t_tokens		*del_empty(t_tokens *read);
// char			del_2mas(char **me, char back);
// char			del_str(char **line);
// void			del_3_str(char **s1, char **s2, char **s3);

// t_op			*check_command(char *l, size_t pos);
// void			check_for_comment(char *line);

// char			label_correct(char *l);
// int				is_number(char *s);

// void			write_magic(t_out *out);

// void			to_file(t_out *output, char *filename);
// void			code_to_bytes(t_tokens *tokens, t_out *out);

// void			*ft_memcpy_rev(void *dst, const void *src, size_t n);

#endif
