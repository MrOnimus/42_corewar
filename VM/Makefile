NAME = ./corewar

FLAGS = -Wall -Wextra -Werror

LIB		= ../libft/libft.a
INCD	= -I../libft/incs/	-I./incs/
SRC = main.c			err_mgmt.c		flag_n.c		game_start.c \
	  gl.c				init.c			init_funcs.c	is_valid.c \
	  print.c

OBJD = objs/
OBJ		= $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(OBJD)%.o: %.c
	@mkdir -p $(OBJD)
	@gcc $(FLAGS) -c $< -o $@ $(INCD)



$(NAME): $(addprefix $(OBJD),$(OBJ))
	@gcc $(FLAGS) $(addprefix $(OBJD), $(OBJ)) $(LIB) $(INCD) -o $(NAME)


debug:
	@gcc -g3 -o $(NAME) $(SRC) $(INCD) -L $(LIB) -lft

clean:
	@rm -rf $(OBJD)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# TODO: Decide what to do with the part down below
## Diff arguments ##

# Write champs from stdin
## e.g CHAMPS = Batman.cor Gangnat.cor
#CHAMPS =

# Dump
## e.g DUMP = 2000
#DEF_DUMP_FLAG = -d
#OURS_DUMP_FLAG = -dump
#DUMP =

#DEF_NAME = defcorewar
#DEF_OUT = def.res
#OURS_OUT = ours.res

#diff_output: ##Usage: make diff_output DUMP=<dump_cycle> CHAMPS=<champs_arg>
#ifeq ($(strip $(CHAMPS)),)
#	@echo "No champs given"
#	@echo "Result is incorrect"
#endif
#Run with not given dump
#ifeq ($(strip $(DUMP)),)
#	$(NAME) $(CHAMPS) > $(OURS_OUT)
#	$(addprefix ./,$(DEF_NAME)) $(CHAMPS) > $(DEF_OUT)
#	diff $(OURS_OUT) $(DEF_OUT)
#else
#	$(NAME) $(OURS_DUMP_FLAG) $(DUMP)  $(CHAMPS) > $(OURS_OUT)
#	$(addprefix ./,$(DEF_NAME)) $(DEF_DUMP_FLAG) $(DUMP) $(CHAMPS) > $(DEF_OUT)
#	diff $(OURS_OUT) $(DEF_OUT)
#endif
## End Diff ##
