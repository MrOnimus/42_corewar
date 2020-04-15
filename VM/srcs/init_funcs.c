#include "corewar.h"

void create_player(t_champion** champions, int num, char* str)
{
	champions[num - 1] = ft_memalloc(sizeof(t_champion));
	champions[num - 1]->number = num;
	champions[num - 1]->reg[1] = -num;
	champions[num - 1]->filename = str;
	/*
		Here we init all players parameters from file
	
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