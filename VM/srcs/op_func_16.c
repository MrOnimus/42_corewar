/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_func_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:08:19 by wned              #+#    #+#             */
/*   Updated: 2020/07/20 22:53:03 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			aff_func(t_rules *rules,
				t_champion *cursor, unsigned char *t_args)
{
	int	arg1;

	arg1 = get_arg(rules, cursor, t_args, 0);
	ft_putchar((char)cursor->reg[arg1]);
}
