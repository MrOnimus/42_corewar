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
	i = 0;
	range = MEM_SIZE / vm->count_players;
	while (i < vm->count_players) {
		ft_memcpy(&(vm->arena[shift]), vm->player[i].code, vm->player[i].code_range);
		shift += range;
		i++;
	}
	
}
