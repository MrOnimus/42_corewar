# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
#                                                 +#+#+#+#+#+   +#+            #
/*   Created: 2020/05/15 19:05:10 by rdremora          #+#    #+#             */
/*   Updated: 2020/07/12 12:13:05 by rdremora         ###   ########.fr       */
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
			translate_to_bytes.c


OBJD = objs/
OBJ		= $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(OBJD)%.o: %.c
	@mkdir -p $(OBJD)
	@gcc $(FLAGS) -c $< -o $@ $(INCD)



$(NAME): $(addprefix $(OBJD),$(OBJ))
	@gcc $(FLAGS) $(addprefix $(OBJD), $(OBJ)) $(LIB) $(INCD) -o $(NAME)

clean:
	@rm -rf $(OBJD)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
