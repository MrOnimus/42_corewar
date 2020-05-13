#include "corewar.h"

int main (int argc, char** argv)
{
	int				num;
	t_champion		**champions;
	t_vm			field;

	num = get_num_of_players(argc, argv);
	
	if (num > MAX_PLAYERS)
		put_error(0);
	else if (num == 0)
		put_error(1);
	else if (num == -1)
		put_error(2);
	else
		printf("Number of Players: %d.\n", num);
	
	if ((champions = ft_memalloc(sizeof(t_champion*) * num)) == NULL)
		put_error(3);
	if (!valid_n_flags(argc, argv, num))
		put_error(4);
	if (!fill_number_players(argc, argv, champions, num))
		put_error(5);
	field.dump = get_dump(argc, argv);
	printf("Dump: %d.\n", field.dump);
	//here we get player struct with name of files, reg1 and num of player

	set_parameters(&field, champions, num);

	print_players(champions, num);
	return (0);
}