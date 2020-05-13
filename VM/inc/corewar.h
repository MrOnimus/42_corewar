#ifndef COMMANDS_H

# define NUM_ERR 11
# define ERR_LENGTH 100
# include <stdio.h>
# include "op.h"
# include <libft.h>

typedef struct			s_champion
{
	int					number;
	char				*name;
	int					filename;
	char				*comment;
	int					reg[REG_NUMBER + 1];
	char				*code;
	int					code_range;
	unsigned int		magic;

	struct s_champion	*next;
}						t_champion;


typedef struct			s_vm
{
	int 				count_players;
	char				arena[MEM_SIZE];
	t_champion			*player;
	int					dump;
	int					much_players;
	int					last_alive;
	char				*name_of_winner;
	int					to_die;	
}						t_vm;

/*
*error func
*/
extern const char		g_error[NUM_ERR][ERR_LENGTH];
void					put_error(int err_code);

/*
*valid func
*/
int	 					valid_n_flags(int argc, char** argv, int num);
int						fill_number_players(int argc, char** argv, t_champion** champions, int n_pl);
int						is_filename(char *filemane, char *ext);


/*
*init func
*/
t_vm 					*init_vm(void);
void					init_arena(t_vm *vm);
void					create_player(t_champion** champions, int num, char* str);
int						get_dump(int argc, char** argv);
int 					get_num_of_players(int argc, char **argv);
void					set_parameters(t_vm *field, t_champion **champions, int num);

/*
*debug functions
*/
void					print_players (t_champion		**champions, int num);
#endif
