/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   libft.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/29 18:24:30 by kgarth-o		  #+#	#+#			 */
/*   Updated: 2020/02/03 16:52:28 by immn			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SZ 1024

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

/*
** COLORS
*/

# define RED 		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define EOC		"\033[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_tree
{
	void			*data;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_stk
{
	int				num;
	struct s_stk	*next;
}					t_stk;

typedef	union		u_double
{
	double			d;
	unsigned long	data;
}					t_double;

typedef	union		u_ldouble
{
	long double		d;
	unsigned long	data[2];
}					t_ldouble;

/*
** TREE
*/

t_tree				*ft_create_node(void *data);
t_tree				*ft_delete_node(t_tree *head, void *data,
									int (*cmp)(void *, void *));
void				ft_insert_data(t_tree **head, void *data,
									int (*cmp)(void *, void *));
void				*ft_search_data(t_tree *head, void *data,
									int (*cmp)(void *, void *));
void				ft_tree_apply_infix(t_tree *head, void (*applyf)(void *));
void				ft_tree_apply_postfix(t_tree *head, void (*applyf)(void *));
void				ft_tree_apply_prefix(t_tree *head, void (*applyf)(void *));

/*
** MATH
*/

long long int		ft_abs(long long int a);

/*
** MEMORY
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);
int					ft_free_darray(char **args);
void				ft_swap(int *a, int *b);
char				*ft_chjoinstr(char c, char *str);
void				ft_free_mas_char(char ***tab);
char				*ft_nchrjoinstr(char *str, char c, int n);

/*
** ARR
*/

void				ft_print_array(int *array, int len);
void				ft_bubble_sort(int *arr, int len);
/*
** LISTS
*/

void				ft_lstrev(t_list **alst);
int					ft_lstlen(t_list *head);
size_t				ft_lstcount(t_list *lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new_list);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_putlst(t_list *head);

/*
** INPUT / OUTPUT
*/

void				ft_print_spaces(int count);
int					ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int c);
int					ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr_chr(const char *s, char *c);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr_fd(int c, int fd);
void				ft_put2str(const char *s1, const char *s2);
int					ft_getchar(void);
int					ft_putwchar(wchar_t wc);
int					ft_putwchar_fd(wchar_t wc, int fd);
void				ft_colorstr(const char *s1, const char *s2, const char *s3);
void				ft_colorstr_nl(const char *s1, const char *s2,
									const char *s3);
void				ft_colorstr_fd(const char *s1, const char *s2,
									const char *s3, int fd);
void				ft_colorstr_nl_fd(const char *s1, const char *s2,
									const char *s3, int fd);
int					ft_putstr_wh(char *s, char c);

/*
** STDLIB
*/

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_bin(unsigned long n, int base, int i);
char				*ft_itoa_pointer(void *p);
long				ft_itoa_round(double tmp);
char				*ft_itoa_double(double nbr, int prec);
char				*ft_itoa_ldouble(long double nbr, int prec);
char				*ft_itoa_u(unsigned long n);
char				*ft_itoa_base(long value, int base, int i);
int					ft_checklong(const char *str);
int					ft_countchars(int n);
char				*ft_intclear(const char *str, int i, int j);
char				*ft_ltoa_base(long long int n, int base);
int					ft_nbrlen_base(unsigned long long int nbr, int base);

/*
** BITS
*/

unsigned int		ft_reverse_bits(unsigned int octet);

/*
** STRING
*/

char				del_str(char **line);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strlen_chr(const char *s, char *c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t size);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup (const char *s);
char				*ft_strnew(size_t size);
int					ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, char const *s2, int clr);
char				*ft_strjoinc_free(char const *s1, char const c, int clr);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_strisalpha(char *str);
int					ft_strislowercase(char *str);
int					ft_strisnumeric(char *str);
int					ft_strisprintable(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
int					ft_strchr_by_index(char *str, int c);
int					ft_word_count(char const *s, char c);
int					ft_count_words(char **arr);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memchr (const void *arr, int c, size_t n);
void				*ft_memmove (void *destination, const void *source,
								size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
int					ft_how_mutch_search_in_str(char *str, char *search);
int					ft_strclen(const char *s, char c);
char				*ft_strjoin_flag(char *s1, int free1, char *s2, int free2);
char				*ft_strjoin_po(char const *s1, char const *s2);
int					ft_strnchr(const char *s, char ch, int n);
char				ft_strrev(char *a);
int					ft_is_ok(char *s, int (*f)(int));//ft_res_is_true
int					is_number(char *s);//ft_is_num


/*
** TOIS
*/

int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_isblank(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

/*
** STACK
*/

void				ft_push_stack(t_stk **stk, int num);
void				ft_print_stack(t_stk *stk);
int					ft_pop_stack(t_stk **stk);
void				ft_free_stack(t_stk *stk);
int					ft_stack_isempty(t_stk *stk);

#endif
