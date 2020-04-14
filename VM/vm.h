//
//  vm.h
//  CoreWar
//
//  Created by  Alex on 14/04/2020.
//  Copyright © 2020  Alex. All rights reserved.
//

#ifndef vm_h
#define vm_h

#include <asm.h>

typedef struct	s_player
{
	char	*code;
	int		code_range;
}				t_player;

typedef struct	s_vm
{
	int 		count_players;
	char		*arena;
	t_player	*player;
	
}				t_vm;

#endif /* vm_h */
