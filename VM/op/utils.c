/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:14:02 by alexandr          #+#    #+#             */
/*   Updated: 2020/07/19 20:40:57 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar.h"

int	step_size(int arg_type, t_op *op)
{
	if (arg_type & T_REG)
		return (REG_LEN);
	else if (arg_type & T_DIR)
		return (op->dir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

int		calc_addr(int addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	return (addr);
}

//Разобраться
int		bytecode_to_int(char	*arena, int addr, int size)
{
	int		result;
	int		sign;
	int			i;

	result = 0;
	sign = (int)(arena[calc_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[calc_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[calc_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int		get_value(int type, t_vm *vm, t_cursor *cursor, int mod, t_op* op)
{
	int addres;

	if (type == 1)
		return (cursor->reg[get_byte(vm, cursor->place, cursor->step) - 1]);
	else if (type == 2)
		return (bytecode_to_int32(vm->arena, cursor->place + cursor->step,
								op->dir_size));
	else if (type == 3)
	{
		addres = bytecode_to_int32(vm->arena, cursor->place + cursor->step, IND_SIZE);
		return (bytecode_to_int32(vm->arena, cursor->place + (mod ? (addres % IDX_MOD) : addres), DIR_SIZE));
	}
	return (0);
}

int		get_op_arg(t_vm *vm, t_cursor *cursor, int index, int mod)
{
	//mod???? false in live and ldi
	t_op* op;
	int type;

	op = &g_op[cursor->op_code - 1];
	type = cursor->args_types[index - 1];
	cursor->step += step_size(cursor->args_types[index - 1], op);
	return (get_value(type, vm, cursor , mod, op));
}


//bytecode_to_int()

void reg_cursor(t_cursor *new, t_cursor *cursor)
{
	int			i;
	
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = cursor->reg[i];
		i++;
	}
}

t_cursor	*copy_cursor(t_cursor *cursor, int addr)
{
	t_cursor	*new;
	

	addr = calc_addr(cursor->place + addr);
	new = init_cursor(cursor->champion, addr);
	reg_cursor(new, cursor);
	new->carry = cursor->carry;
	new->last_live = cursor->last_live;
	return (new);
}

void	add_cursor(t_cursor **list, t_cursor *new)
{
	if (new)
		new->next = *list;
	*list = new;
}

void		update_map(t_vm *vm, t_cursor *cursor, int addr, int size)
{
	int value;

	value = ((cursor->player->id - 1) % MAX_PLAYER_ID) + 1;
	while (size)
	{
		vm->vs->map[calc_addr(addr + size - 1)].index = value;
		vm->vs->map[calc_addr(addr
								+ size - 1)].wait_cycles_store = CYCLE_TO_WAIT;
		size--;
	}
}