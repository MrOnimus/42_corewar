# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdremora <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 19:15:09 by aschimme          #+#    #+#              #
#    Updated: 2020/09/11 00:05:54 by rdremora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../asm

FLAGS	= -Wall -Wextra -Werror

LIB		= ../libft/libft.a
INCD	= -I../libft/incs/	-I./incs/
SRC		=	main.c error_msg.c		first_validation.c	translate_to_bin.c		\
			top_part_of_file.c		s_out.c				reading_instructions.c	\
			reading_instruments.c	global_variables.c	parse_args.c			\
			s_tokens.c				s_mark.c			struct_free.c			\
			translate_to_bytes.c	reading_instruments2.c

# COLORS
RED             =   \033[0;31m
GREEN           =   \033[0;32m
YELLOW          =   \033[0;33m
BLUE            =   \033[0;34m
PURPLE          =   \033[0;35m
L_BLUE          =   \033[0;36m
NC              =   \033[0m

OBJD = objs/
OBJ		= $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(OBJD)%.o: %.c
	@mkdir -p $(OBJD)
	@gcc $(FLAGS) -c $< -o $@ $(INCD)

libft:
	@make -s -C ../libft all

$(NAME): libft $(addprefix $(OBJD),$(OBJ))
	@echo "\r\033[K$(GREEN)Creating assembler$(NC): $(YELLOW)$(NAME)$(NC)"
	@gcc $(FLAGS) $(addprefix $(OBJD), $(OBJ)) $(LIB) $(INCD) -o $(NAME)
	@echo "$(GREEN)DONE$(NC)"


clean:
	@make -s -C ../libft clean
	@rm -rf $(OBJD)
	@echo "$(RED)Cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

fclean: clean
	@make -s -C ../libft fclean
	@rm -rf $(NAME)
	@echo "$(RED)Full cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

re: fclean all
