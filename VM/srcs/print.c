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