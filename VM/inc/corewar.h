#ifndef COMMANDS_H

# define MAX_OF_PLAYERS 4
# define NUM_ERR 7
# define ERR_LENGTH 100
# define REG_NUMBER 16
# include <stdio.h>
# include "../../libft/includes/libft.h"

typedef struct			s_champion
{
	int					number;
	char				*filename;
	char				*comment;
	int					reg[REG_NUMBER + 1];

	struct s_champion	*next;
}						t_champion;
extern const char	g_error[NUM_ERR][ERR_LENGTH];
int 				get_num_of_players(int argc, char **argv);
int	 				valid_n_flags(int argc, char** argv, int num);
int					fill_number_players(int argc, char** argv, t_champion** champions, int n_pl);
void				put_error(int err_code);

#endif
