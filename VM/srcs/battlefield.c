/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battlefield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 07:53:19 by elchrist          #+#    #+#             */
/*   Updated: 2020/07/09 18:54:02 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	champion_move_battlefield(t_champion *champion,
	t_rules *rules, int position)
{
	int	count;

	count = 0;
	champion->position = position;
	while (count < champion->size)
	{
		rules->battlefield[position] = champion->body[count];
		position++;
		count++;
	}
}

void	create_battlefield(t_rules *rules, t_champion **champions)
{
	int current_champion;
	int count;

	count = 0;
	current_champion = 1;
	while (count < rules->much_players)
	{
		while (champions[current_champion] == NULL)
			current_champion++;
		champion_move_battlefield(champions[current_champion++],
		rules, count * (MEM_SIZE / rules->much_players));
		count++;
	}
}
