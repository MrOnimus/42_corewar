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

void print_logo()
{
	ft_printf("╔═══╦═══╦═══╦═══╗ ╔═╗╔╗╔═╦═══╦═══╗\n");
	ft_printf("║╔══╣╔═╗║╔═╗║╔══╝ ║ ║║║║ ║╔═╗║╔═╗║\n");
	ft_printf("║║  ║║ ║║╚═╝║╚══╗ ║ ║║║║ ║╚═╝║╚═╝║\n");
	ft_printf("║║  ║║ ║║╔╗╔╣╔══╝ ║ ║║║║ ║╔═╗║╔╗╔╝\n");
	ft_printf("║╚══╣╚═╝║║║║║╚══╗ ║ ╚╝╚╝ ║║ ║║║║║\n");
	ft_printf("╚═══╩═══╩╝╚╝╚═══╝ ╚══╝╚══╩╝ ╚╩╝╚╝\n");
	ft_printf("\n");
}

void intro(t_champion **champions, int num)
{
	int index;

	index = 1;
	ft_printf("Introducing contestants...\n");
	while (index <= num)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
												index,
												champions[index - 1]->code_range,
												champions[index - 1]->name,
												champions[index - 1]->comment);
		index++;
	}
}
