#include "header.h"

int main (int argc, char** argv)
{
	int				num;
	t_champion		**champions;

	num = get_num_of_players(argc, argv);
	if (num > MAX_OF_PLAYERS)
	{
		printf("Too many champions.\n");
		return (0);
	}
	else if (num == 0)
	{
		printf("No arguments.\n");
		return (0);
	}
	else if (num == -1)
	{
		printf("Wrong argument after -n or -dump.\n");
		return (0);
	}
	else
		printf("Number of Player: %d.\n", num);
	if ((champions = ft_memalloc(sizeof(t_champion*) * num)) == NULL)
	{
		printf("Mall\n");
		return (0);
	}
	if (!valid_n_flags(argc, argv, champions))
	{
		printf("Error argument after flag -n\n");
		return (0);
	}
	return (0);
}