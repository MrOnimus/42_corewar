/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_to_bytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:31:22 by immn              #+#    #+#             */
/*   Updated: 2020/02/24 16:46:24 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void				args_circle(t_tokens *tokens, t_out *out, int *i)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		if (tokens->types[j] == 1)
			ft_memcpy_rev(&(out->code[(*i)++]), &(tokens->values[j]), 1);
		else if (tokens->types[j] == 2 || tokens->types[j] == 4)
		{
			if (tokens->command->dir_size == 2 || tokens->types[j] == 4)
				ft_memcpy_rev(&(out->code[*i]), &(tokens->values[j]), 2);
			else
			{
				ft_memcpy_rev(&(out->code[*i]), &(tokens->values[j]), 4);
				*i += 2;
			}
			*i += 2;
		}
		// else if (tokens->types[j] == 4)
		// {
		// 	ft_memcpy_rev(&(out->code[*i]), &(tokens->values[j]), 2);
		// 	*i += 2;
		// }
		j++;
	}
}

static char				the_code(char me)
{
	if (me == T_IND)
		return (3);
	else if (me == T_DIR)
		return (2);
	else if (me == T_REG)
		return (1);
	return (0);
}

static unsigned char	typecode(t_tokens *tokens)
{
	unsigned char	res;
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;

	a = the_code(tokens->types[0]);
	b = the_code(tokens->types[1]);
	c = the_code(tokens->types[2]);
	res = 0 | ((a << 6) & IIOOOOOO) | ((b << 4) & OOIIOOOO) | ((c << 2) & OOOOIIOO);
	return (res);
}

void					code_to_bytes(t_tokens *tokens, t_out *out)
{
	int	i;

	i = 0;
	out->code = ft_memalloc(out->code_size_int);
	while (tokens)
	{
		out->code[i] = tokens->command->opcode;
		i++;
		if (tokens->command->a_typecode)
		{
			out->code[i] = typecode(tokens);
			i++;
		}
		args_circle(tokens, out, &i);
		tokens = tokens->next;
	}
	ft_memcpy_rev(out->code_size, &i, sizeof(int));
}
