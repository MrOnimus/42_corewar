#ifndef COMMANDS_H

# define NUM_ERR 7
# define ERR_LENGTH 100
# include <stdio.h>
# include "op.h"
# include "../../libft/includes/libft.h"

typedef struct			s_champion
{
	int					number;
	char				*name;
	char				*filename;
	char				*comment;
	int					reg[REG_NUMBER + 1];

	struct s_champion	*next;
}						t_champion;


typedef struct			s_vm
{
	int 				count_players;
	char				*arena;
	t_champion			*player;
	int					dump;
	int					much_players;
	int					last_alive;
	char				*name_of_winner;
	int					to_die;	
	}						t_vm;

extern const char		g_error[NUM_ERR][ERR_LENGTH];
int 					get_num_of_players(int argc, char **argv);
int	 					valid_n_flags(int argc, char** argv, int num);
int						fill_number_players(int argc, char** argv, t_champion** champions, int n_pl);
void					put_error(int err_code);
int						get_dump(int argc, char** argv);
void					create_player(t_champion** champions, int num, char* str);
void					set_parameters(t_vm *field, t_champion **champions, int num);


//debug functions
void					print_players (t_champion		**champions, int num);
#endif
