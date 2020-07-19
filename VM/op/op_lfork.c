/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:12:19 by alexandr          #+#    #+#             */
/*   Updated: 2020/07/18 14:23:17 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar.h"
/**
 * means long-fork, to be able to fork abut straw from a distance of 15 meters,
	exactly like with its opcode. Same as a fork without modulo in the address.
*/

// lfork: means long-fork, to be able to fork abut straw from a distance of 15 meters,
// exactly like with its opcode. Same as a fork without modulo in the address

void				op_lfork(t_vm *vm, t_cursor *cursor)
{
	int		addres;
	t_cursor	*new;

	cursor->step += OP_CODE_LEN;
	addres = get_op_arg(vm, cursor, 1, 1);
	new = copy_cursor(cursor, addres);
	add_cursor(&(vm->cursors), new);
	vm->cursor_num++;
	// if (vm->log & OP_LOG)
	// 	log_lfork(cursor, addr);
}
