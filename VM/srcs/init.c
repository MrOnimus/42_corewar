//
//  init.c
//  CoreWar
//
//  Created by  Alex on 14/04/2020.
//  Copyright © 2020  Alex. All rights reserved.
//

#include "corewar.h"

//t_champion	*champ_list()
//{
//	t_champion	*champs;
//
//	if(!(champs = (t_champion *)ft_memalloc(sizeof(t_champion))))
//		put_error(3);
//
//	return champs;
//}


t_vm *init_vm()
{
    t_vm *vm;

    if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
        put_error(3);
    vm->count_players = 0;
    vm->player = NULL;
    vm->last_alive = NULL;
    vm->cycle = 0;
    vm->cycles_after_check = 0;
    vm->cycles_to_die = CYCLE_TO_DIE;
    vm->cursors = NULL;
    vm->cursor_num = 0;

    return (vm);
}

void init_arena(t_vm *vm)
{
	int range;
	int i;
	int shift;

	shift = 0;
	i = 0;
	range = MEM_SIZE / vm->count_players;
	while (i < vm->count_players) {
		ft_memcpy(&(vm->arena[shift]), vm->player[i].code, vm->player[i].code_range);
		shift += range;
		i++;
	}

}
