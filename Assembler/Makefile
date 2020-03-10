# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 13:59:19 by immn              #+#    #+#              #
#    Updated: 2020/03/10 20:33:50 by rdremora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../asm

FLAGS	= -Wall -Wextra -Werror

LIB		= ../libft/libft.a
INC		= -I../libft/includes/	-I./inc/
SRC		=	main.c error_msg.c		first_validation.c	translate_to_bin.c		\
			top_part_of_file.c		s_out.c				reading_instructions.c	\
			reading_instruments.c	global_variables.c	parse_args.c			\
			s_tokens.c				s_mark.c			struct_free.c			\
			translate_to_bytes.c
			

OBJ_DIR = obj/
OBJ		= $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ))
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(OBJ)) $(LIB) $(INC) -o $(NAME)

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all
