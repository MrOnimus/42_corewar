#include "ft_printf.h"
#include "corewar.h"

void	op_aff(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (vm->display_aff)
		ft_printf("Aff: %c\n", (char)value);
	if (vm->vs)
	{
		vm->vs->aff_symbol = (char)value;
		vm->vs->aff_player = cursor->player;
	}
}


//сделать или найти русскую  документацию команд по корвару

