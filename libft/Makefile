# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2019/10/29 12:46:09 by kgarth-o		  #+#	#+#			  #
#	Updated: 2020/02/03 16:22:02 by immn			 ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME			= 	libft.a
CC				= 	gcc
SRCD			=	./srcs/
OBJD			=	./objs/
FLAGS			=	-Wall -Wextra -Werror -O3 -Ofast
INCLUDES_D		=	includes/

_INCLUDES		=	libft.h					get_next_line.h					ft_printf.h

_MEM_FS			=	ft_memchr.c				ft_memccpy.c					ft_memmove.c			\
					ft_memcpy.c				ft_realloc.c					ft_memcmp.c				\
					ft_bzero.c				ft_memalloc.c					ft_memdel.c 			\
					ft_memset.c				ft_free_darray.c				ft_swap.c				\
					ft_nchrjoinstr.c		ft_memcpy_rev.c

_ARR_FS			=	ft_print_arr.c			ft_bubble_sort.c				ft_free_mas_char.c

_IO_FS			= 	ft_putendl.c			ft_putnbr.c						ft_putchar_fd.c			\
					ft_putstr_fd.c 			ft_putendl_fd.c					ft_putnbr_fd.c			\
					ft_putwchar.c			ft_putchar.c					ft_putwchar_fd.c		\
					ft_putstr.c				get_next_line.c					ft_colorstr.c			\
					ft_colorstr_nl.c		ft_colorstr_fd.c				ft_colorstr_nl_fd.c		\
					ft_putstr_chr.c			ft_print_spaces.c				ft_putstr_wh.c

_TYPES_FS		=	ft_atoi.c				ft_isblank.c					ft_islower.c			\
					ft_isspace.c			ft_isupper.c					ft_isxdigit.c			\
					ft_isgraph.c			ft_iscntrl.c					ft_strisprintable.c		\
					ft_itoa.c				ft_isalpha.c					ft_isdigit.c			\
					ft_tolower.c			ft_isalnum.c					ft_isascii.c			\
					ft_isprint.c			ft_toupper.c					ft_atol.c				\
					ft_min.c				ft_max.c						ft_itoa_base.c			\
					ft_itoa_bin.c			ft_itoa_double.c				ft_itoa_ldouble.c		\
					ft_itoa_pointer.c		ft_itoa_roundd.c				ft_itoa_u.c				\
					ft_strisnumeric.c		ft_strislowercase.c				ft_strisalpha.c			\
					ft_checklong.c			ft_chjoinstr.c					ft_countchars.c			\
					ft_intclear.c			ft_ltoa_base.c					ft_nbrlen_base.c		

_LIST_FS		=	ft_lstiter.c			ft_lstmap.c						ft_lstdelone.c			\
					ft_lstdel.c				ft_lstadd.c						ft_lstnew.c				\
					ft_lstcount.c			ft_lstlen.c						ft_lstrev.c				\
					ft_putlst.c

_BTREE_FS		=	ft_create_node.c		ft_delete_node.c				ft_insert_data.c		\
					ft_search_data.c		ft_tree_apply_infix.c			ft_tree_apply_postfix.c	\
					ft_tree_apply_infix.c \

_STR_FS			=	ft_strnstr.c			ft_strcmp.c						ft_strncmp.c			\
					ft_strnew.c				ft_strdel.c						ft_strclr.c				\
					ft_striter.c			ft_striteri.c					ft_strmap.c				\
					ft_strmapi.c			ft_strequ.c						ft_strnequ.c			\
					ft_strsub.c				ft_strjoin.c					ft_strtrim.c			\
					ft_strsplit.c			ft_strlen.c						ft_strjoin_free.c		\
					ft_strjoinc_free.c		ft_strdup.c						ft_strcpy.c				\
					ft_strncpy.c			ft_strcat.c						ft_strncat.c			\
					ft_strlcat.c			ft_strchr.c						ft_strrchr.c			\
					ft_strstr.c				ft_strchr_by_index.c			ft_word_count.c			\
					ft_count_words.c		ft_strlen_chr.c					ft_strupcase.c			\
					ft_strlowcase.c			ft_how_mutch_search_in_str.c 	ft_strclen.c			\
					ft_strjoin_flagclear.c	ft_strjoin_po.c					ft_strnchr.c			\
					ft_strrev.c				del_str.c						ft_res_is_true.c		\
					ft_is_num.c

_STACK_FS		=	ft_free_stack.c			ft_pop_stack.c					ft_print_stack.c		\
					ft_stack_isempty.c 		ft_push_stack.c

_BITS_FS		=	ft_reverse_bits.c

_PRINT_FS		=	double.c				ft_printf.c						init.c					\
					io.c					num.c							precision.c				\
					str.c					spec.c

_MATH_FS		=	ft_abs.c

ARR_FS			=	$(addprefix $(SRCD)ft_arr/,$(_ARR_FS))
ARR_O			=	$(_ARR_FS:.c=.o)
TYPES_FS		=	$(addprefix $(SRCD)ft_types/,$(_TYPES_FS))
TYPES_O			=	$(_TYPES_FS:.c=.o)
BTREE_FS		=	$(addprefix $(SRCD)ft_btree/,$(_BTREE_FS))
BTREE_O			=	$(_BTREE_FS:.c=.o)
LIST_FS			=	$(addprefix $(SRCD)ft_list/,$(_LIST_FS))
LIST_O			=	$(_LIST_FS:.c=.o)
MEM_FS			=	$(addprefix $(SRCD)ft_mem/,$(_MEM_FS))
MEM_O			=	$(_MEM_FS:.c=.o)
IO_FS			=	$(addprefix $(SRCD)ft_io/,$(_IO_FS))
IO_O			=	$(_IO_FS:.c=.o)
STR_FS			=	$(addprefix $(SRCD)ft_str/,$(_STR_FS))
STR_O			=	$(_STR_FS:.c=.o)
STACK_FS		=	$(addprefix $(SRCD)ft_stack/,$(_STACK_FS))
STACK_O			=	$(_STACK_FS:.c=.o)
PRINT_FS		=	$(addprefix $(SRCD)ft_printf/,$(_PRINT_FS))
PRINT_O			=	$(_PRINT_FS:.c=.o)
BITS_FS			=	$(addprefix $(SRCD)ft_bits/,$(_BITS_FS))
BITS_O			=	$(_BITS_FS:.c=.o)
MATH_FS			=	$(addprefix $(SRCD)math/,$(_MATH_FS))
MATH_O			=	$(_MATH_FS:.c=.o)

SRCS			=	$(MATH_FS) $(TYPES_FS) $(BTREE_FS) $(LIST_FS) \
					$(MEM_FS) $(IO_FS) $(STR_FS) $(STACK_FS) $(PRINT_FS) \
					$(ARR_FS)

OBJS			=	$(MATH_O) $(TYPES_O) $(BTREE_O) $(LIST_O) \
					$(MEM_O) $(IO_O) $(STR_O) $(STACK_O) $(PRINT_O) \
					$(ARR_O)

OBJB			=	$(addprefix $(OBJD), $(OBJS))

# COLORS
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
L_BLUE			=	\033[0;36m
NC				=	\033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJB)
	@printf "\r\033[K$(GREEN)Creating library$(NC): $(YELLOW)$(NAME)$(NC)\n"
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)
	@echo "$(GREEN)DONE$(NC)"

$(OBJD)%.o : $(SRCD)ft_math/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o : $(SRCD)ft_btree/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o : $(SRCD)ft_types/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o : $(SRCD)ft_list/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o : $(SRCD)ft_stack/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o : $(SRCD)ft_mem/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_io/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_str/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_printf/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_arr/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)math/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)
clean:
	@rm -rf $(OBJB)
	@echo "$(RED)Cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

fclean:
	@rm -rf $(OBJB)
	@rm -rf $(NAME)
	@rm -rf $(OBJD)
	@echo "$(RED)Full cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

re:
	@make fclean
	@make all
