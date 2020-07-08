#ifndef COMMANDS_H

<<<<<<< HEAD
# define NUM_ERR 8
# define ERR_LENGTH 100
# include <stdio.h>
# include "op.h"
# include "../../libft/includes/libft.h"
=======
# define NUM_ERR 11
# define ERR_LENGTH 100
# include <stdio.h>
# include "op.h"
# include <libft.h>
>>>>>>> origin/feature/alex/init_arena

typedef struct			s_champion
{
	int					number;
	char				*name;
<<<<<<< HEAD
	char				*filename;
	char				*comment;
	int					code_size;
	int					reg[REG_NUMBER + 1];
=======
	int					filename;
	char				*comment;
	int					reg[REG_NUMBER + 1];
	char				*code;
	int					code_range;
	unsigned int		magic;
>>>>>>> origin/feature/alex/init_arena

	struct s_champion	*next;
}						t_champion;


<<<<<<< HEAD


typedef struct			s_cursor
{
	int					id;
	int					carry;
	int					op_code;
	int					last_live;
	int					cycles_to_exec;
	int					args_types[3];
	int					place;
	int					step;
	int					reg[REG_NUMBER];
	t_champion			*champion;
	struct s_cursor		*next;
}						t_cursor;
//struct from braznik


typedef struct			s_vm
{
	int 				count_players;
	char				*arena;
=======
typedef struct			s_vm
{
	int 				count_players;
	char				arena[MEM_SIZE];
>>>>>>> origin/feature/alex/init_arena
	t_champion			*player;
	int					dump;
	int					much_players;
	int					last_alive;
	char				*name_of_winner;
<<<<<<< HEAD
	int					to_die;
	int					cursor_num;
	int					cycle;
	int					cycles_after_check;
	int					cycles_to_die;
	t_cursor			*cursors;
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
//print
void					print_logo();
void 					intro(t_champion **champions, int num);
void					execute(t_vm *vm);

=======
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
>>>>>>> origin/feature/alex/init_arena
#endif
