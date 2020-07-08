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
