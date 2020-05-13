#include "corewar.h"

void create_player(t_champion** champions, int num, char* str)
{
	champions[num - 1] = ft_memalloc(sizeof(t_champion));
	champions[num - 1]->number = num;
	champions[num - 1]->reg[1] = -num;
	champions[num - 1]->filename = is_filename(str, ".cor");
	champions[num - 1]->name = ft_strsub(str, 0, ft_strlen(str) - 4);
	
	/*
		Here we init all players parameters from file
	fd
	check magic header
	long of program name - lseek
	check size
	get and check name
	get and check comment
	give colour?
	get code
	*/
}

int get_dump(int argc, char** argv)
{
	int i;
	int dump;

	i = 0;
	dump = 0;
	while (++i < argc)
		if (!ft_strequ(argv[i], "-dump"))
			dump = ft_atoi(argv[i]);		
	return dump;
}


int get_num_of_players(int argc, char **argv)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (++i < argc)
		if (!ft_strequ(argv[i], "-dump") && !ft_strequ(argv[i], "-n"))
			res++;
		else if (ft_strequ(argv[i], "-dump") && i + 1 < argc && ft_strisnumeric(argv[i + 1]))
			i++;
		else if (ft_strequ(argv[i], "-n") && i + 2 < argc && ft_strisnumeric(argv[i + 1]) &&
			!ft_strequ(argv[i + 2], "-dump") && !ft_strequ(argv[i + 2], "-n"))
			i++;
		else
			return (-1);//После флага ничего нет, либо не натуральное число или ноль		
	return res;
}

void		set_parameters(t_vm *field, t_champion **champions, int num)
{
	field->last_alive = num;
	field->name_of_winner = champions[num - 1]->name;
	field->to_die = CYCLE_TO_DIE;
}
