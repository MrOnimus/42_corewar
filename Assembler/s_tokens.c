/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tokens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:25:33 by aschimme          #+#    #+#             */
/*   Updated: 2020/07/14 08:44:16 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	del_tokens(t_tokens *me)
{
	t_tokens	*tmp;

	while (me)
	{
		tmp = me->next;
		free(me->mark);
		free(me->a1);
		free(me->a2);
		free(me->a3);
		free(me);
		me = tmp;
	}
}

void		*free_return(t_tokens *new)
{
	del_tokens(new);
	return (NULL);
}

void		add_tok(t_tokens **toks, t_tokens **curr, t_tokens *new)
{
	if (!*toks)
	{
		*toks = new;
		*curr = *toks;
	}
	else
	{
		(*curr)->next = new;
		*curr = (*curr)->next;
	}
}

t_tokens		*del_empty(t_tokens *read)
{
	t_tokens	*tmp;
	t_tokens	*new;

	new = read;
	while (read && read->next)
	{
		if (!(read->next->command))
		{
			tmp = read->next;
			read->next = read->next->next;
			free(tmp);
		}
		else
			read = read->next;
	}
	if (!(new->command))
	{
		tmp = new->next;
		free(new);
		return (tmp);
	}
	return (new);
}
