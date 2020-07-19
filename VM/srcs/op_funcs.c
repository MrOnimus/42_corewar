#include "corewar.h"

int		get_addr(int addr)
{
	addr %= MEM_SIZE;
	// if (addr < 0)
	// 	addr += MEM_SIZE;
	return (addr);
}


int	get_byte(t_vm *vm, int pc, int step)
{
	return (vm->arena[get_addr(pc + step)]);
}