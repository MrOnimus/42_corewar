//
//  init.c
//  CoreWar
//
//  Created by  Alex on 14/04/2020.
//  Copyright © 2020  Alex. All rights reserved.
//

#include "vm.h"

void init_arena(t_vm *vm)
{
	int range;
	int i;
	int shift;
	
	vm->arena = ft_memalloc(MEM_SIZE);
	shift = 0;
	range = MEM_SIZE / vm->count_players;
	for (i = 0; i < vm->count_players; i++) {
		ft_memcpy(&(vm->arena[shift]), vm->player[i].code, vm->player[i].code_range);
		shift += range;
	}
	
}
