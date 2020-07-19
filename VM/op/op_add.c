#include "ft_printf.h"
#include "corewar.h"

// inline static void	log_add(int cursor_id,
// 							int r1,
// 							int r2,
// 							int r3)
// {
// 	ft_printf("P %4d | add r%d r%d r%d\n", cursor_id, r1, r2, r3);
// }
/**
	Take three registries, add the first two, and place the result in the
	third, right before modifying the carry.
*/
void				op_add(t_vm *vm, t_cursor *cursor)
{
	int	r1;
	int	r2;
	int	r3;
	int	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1 = get_byte(vm, cursor->id, cursor->step);
	cursor->step += REG_LEN;
	r2 = get_byte(vm, cursor->id, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[r1 - 1] + cursor->reg[r2 - 1];
	cursor->carry = (int)(!value);							//?
	r3 = get_byte(vm, cursor->id, cursor->step);
	cursor->reg[r3 - 1] = value;
	cursor->step += REG_LEN;
	// if (vm->log & OP_LOG)
	// 	log_add(cursor->id, r1, r2, r3);
}
