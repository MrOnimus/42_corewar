#include "header.h"
int get_num_of_players(int argc, char **argv)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (++i < argc)
		if (!ft_strequ(argv[i], "-dump") && !ft_strequ(argv[i], "-n"))
			res++;
		else if (i + 1 < argc && ft_strisnumeric(argv[i + 1]))
			i++;
		else
			return (-1);//После флага ничего нет, либо не натуральное число или ноль		
	return res;
}

int valid_n_flags(int argc, char** argv, t_champion** champions)
{
	
	return (0);
}