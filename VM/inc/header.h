#ifndef COMMANDS_H

# define MAX_OF_PLAYERS 4
# include <stdio.h>
# include "../libft/includes/libft.h"


typedef struct			s_champion
{
	int					number;
	char				*name;
	char				*comment;

	struct s_champion	*next;
}						t_champion;
int get_num_of_players(int argc, char **argv);
int valid_n_flags(int argc, char** argv, t_champion** champions);

#endif
