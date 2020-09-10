/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:08:38 by rdremora          #+#    #+#             */
/*   Updated: 2020/09/10 18:27:37 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

void	clean_memory(t_champion **cursors)
{
	t_champion *current;
	t_champion *next;

	current = *cursors;
	while (current != NULL)
	{
		next = current->next;
		del_str((char**)&(current->body));
		del_str(&(current->comment));
		del_str(&(current->name));
		del_str(&(current->color));
		free(current);
		current = next;
	}
	if (*cursors != NULL)
		free(*cursors);
}

void	end_game(int reason, t_rules *rules, t_champion **champions)
{
	if (reason == PRINTING_DUMP)
		print_dump(rules);
	else if (reason == GAME_OVER)
	{
		ft_printf("Contestant %d, \"%s\", has won !\n", rules->last_alive,
		g_names_tab[rules->last_alive]);
		exit(0);
	}
	clean_memory(champions);
	del_str(&(rules->name_winner));
	exit(0);
}
