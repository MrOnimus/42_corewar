#include "corewar.h"

void print_players (t_champion		**champions, int num)
{
	int i = 0;
	while (i < num)
	{
		printf("Index i = %d,  Player: %d, name: %s\n", i, champions[i]->number, champions[i]->filename);
		i++;
	}
}

int main (int argc, char** argv)
{
	int				num;
	t_champion		**champions;

	num = get_num_of_players(argc, argv);
	if (num > MAX_OF_PLAYERS)
		put_error(0);
	else if (num == 0)
		put_error(1);
	else if (num == -1)
		put_error(2);
	else
		printf("Number of Player: %d.\n", num);
	
	if ((champions = ft_memalloc(sizeof(t_champion*) * num)) == NULL)
		put_error(3);
	if (!valid_n_flags(argc, argv, num))
		put_error(4);
	if (!fill_number_players(argc, argv, champions, num))
		put_error(5);
	print_players(champions, num);
	return (0);
}