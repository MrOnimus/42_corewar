/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 00:20:35 by aschimme          #+#    #+#             */
/*   Updated: 2020/09/10 18:30:29 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define NO_COLOR	"\033[m"

# include "../../libft/incs/libft.h"
# include "op.h"

typedef struct			s_champion
{
	int					number_cursors;
	int					number;
	int					fd;
	char				*name;
	char				*comment;
	unsigned char		*body;
	int					reg[REG_NUMBER + 1];
	int					size;
	int					position;
	char				*color;
	int					carry;
	int					code_operation;
	int					last_live_in_cycle;
	int					cycle_before_run;
	int					bytes_for_next_operation;
	void				(*to_string)(struct s_champion* cursor, char flag_body);
	struct s_champion	*next;
}						t_champion;

/*
**	dump;
**	number_cursors;		количество кареток
**	much_players;		количество игроков
**	last_alive;			последний прокукарекавший петух
**	number_cycle;		Количество циклов с начала игры
**	num_live_of_ctd;	Количество выполненых операций live за CYCLE_TO_DIE
**	ctd;				CYCLE_TO_DIE - длительность периода до проверки
**	number_check;		Количество проведёных проверок
**	*cursors;			Указатель на начало списка кареток
*/

typedef struct			s_rules
{
	int					dump;
	int					number_cursors;
	int					much_players;
	unsigned char		battlefield[MEM_SIZE];
	int					last_alive;
	char				*name_winner;
	int					number_cycle;
	int					num_live_of_ctd;
	int					ctd;
	int					number_check;
	t_champion			*cursors;
}						t_rules;

/*
**  Parsing
*/

void					error_msg(int err_code);
int						get_num_of_players(int argc, char **argv);
int						all_valid(int argc, char **argv,
							t_champion **champions, t_rules *rules);

/*
**  Read and create champion
*/

char					*read_name(int fd, int current_num);
char					*read_comment(int fd);
int						read_body(int fd, t_champion *champion);
int						create_champion(t_champion **champions,
							int fd, int current_num);

void					print_bytes_hex(unsigned char *bytes, int size);
void					create_battlefield(t_rules *rules,
							t_champion **champions);
void					print_battlefiled(t_rules *rules,
							t_champion **champions);
int						select_champion(t_champion **champions,
							int current_champion);
t_champion				*create_cursor(t_champion **champions, t_rules *rules);
void					print_cursors(t_champion *cursor, char flag_body);
void					to_string(t_champion *cursors, char flag_body);

/*
**	flag_body == 1 body print
**	flag_body == 0 body no print
*/

void					print_rules(t_rules *rules);
void					start_game(t_rules *rules,
							t_champion **champions);
t_champion				*add_cursor_in_start(t_champion *cursors,
							t_champion *champion);
t_champion				*delete_cursor(t_champion *del_cursor,
							t_champion **cursors, t_champion *prev,
							t_rules *rules);
void					check_cursors(t_champion **cursors, t_rules *rules);
void					exec_command(t_rules *rules, t_champion *cursor);
int						count_size_args(unsigned char *type_args,
							int how_many_arg, int op_code);
int						allowed_args(int op_code, unsigned char args_code,
							unsigned char *types_args);
void					print_dump(t_rules *rules);
void					free_cursor(t_champion **cursor);
int						get_arg(t_rules *rules, t_champion *cursor,
							unsigned char *t_args, int num_arg);
void					end_game(int reason, t_rules *rules,
							t_champion *cursors, t_champion **champions);
int						valid_n_flags(int argc, char **argv,
							t_champion **champions, t_rules *rules);

typedef void			(*t_op_func)(t_rules*, t_champion*, unsigned char*);

#endif
