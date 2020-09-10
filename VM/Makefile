# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschimme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 19:11:03 by aschimme          #+#    #+#              #
#    Updated: 2020/09/10 19:14:50 by aschimme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

SRCS = $(wildcard srcs/*.c)

OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))

FLAGS = -Wall -Wextra -Werror

INC = ./includes

LIBRARY = ../libft/

# COLORS
RED             =   \033[0;31m
GREEN           =   \033[0;32m
YELLOW          =   \033[0;33m
BLUE            =   \033[0;34m
PURPLE          =   \033[0;35m
L_BLUE          =   \033[0;36m
NC              =   \033[0m

all: $(NAME)

libft: 
	@make -C ../libft all

$(NAME): libft $(OBJS)
	@echo "\r\033[K$(GREEN)Creating corewar$(NC): $(YELLOW)$(NAME)$(NC)"
	@gcc -o $(NAME) $(OBJS) -I $(INC) -L ./$(LIBRARY) -lft
	@echo "$(GREEN)DONE$(NC)"

objs/%.o: srcs/%.c
	@mkdir -p objs
	@gcc -c $(FLAGS)  $< -o $@ -I $(INC)

debug:
	@gcc -g3 -o $(NAME) $(SRCS) -I $(INC) -L ./$(LIBRARY) -lft

clean:
	@make clean -C ../libft
	@rm -f $(OBJS)
	@echo "$(RED)Cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

fclean: clean
	@make fclean -C ../libft
	@rm -f $(NAME)
	@echo "$(RED)Full cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

re: fclean all

## Diff arguments ##

# Write champs from stdin
## e.g CHAMPS = Batman.cor Gangnat.cor
CHAMPS =

# Dump
## e.g DUMP = 2000
DEF_DUMP_FLAG = -d
OURS_DUMP_FLAG = -dump
DUMP =

DEF_NAME = defcorewar
DEF_OUT = def.res
OURS_OUT = ours.res

diff_output: ##Usage: make diff_output DUMP=<dump_cycle> CHAMPS=<champs_arg>
ifeq ($(strip $(CHAMPS)),)
	@echo "No champs given"
	@echo "Result is incorrect"
endif
#Run with not given dump
ifeq ($(strip $(DUMP)),)
	$(NAME) $(CHAMPS) > $(OURS_OUT)
	$(addprefix ./,$(DEF_NAME)) $(CHAMPS) > $(DEF_OUT)
	diff $(OURS_OUT) $(DEF_OUT)
else
	$(NAME) $(OURS_DUMP_FLAG) $(DUMP)  $(CHAMPS) > $(OURS_OUT)
	$(addprefix ./,$(DEF_NAME)) $(DEF_DUMP_FLAG) $(DUMP) $(CHAMPS) > $(DEF_OUT)
	diff $(OURS_OUT) $(DEF_OUT)
endif
# End Diff ##
