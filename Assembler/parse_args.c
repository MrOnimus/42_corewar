/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: immn <immn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:55:23 by immn              #+#    #+#             */
/*   Updated: 2020/02/17 10:14:03 by immn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_bad_args(t_tokens *new, int n_arg, char **args)
{
	if (args[0] && !args[0][0])
	{
		free(args[0]);
		args[0] = NULL;
	}
	if (n_arg > 1 && !args[1][0])
	{
		free(args[1]);
		args[1] = NULL;
	}
	if (n_arg > 2 && !args[2][0])
	{
		free(args[2]);
		args[2] = NULL;
	}
	new->a1 = args[0];
	new->a2 = n_arg > 1 ? args[1] : NULL;
	new->a3 = n_arg > 2 ? args[2] : NULL;
}

static char		check_value(int *value, char **s)
{
	char	*tmp;

	if (**s == LABEL_CHAR)
	{
		tmp = ft_strdup(*s + 1);
		free(*s);
		*s = tmp;
		if (!label_correct(*s) && (g_error.id = 11))
			return (1);
	}
	else
	{
		*value = ft_atoi(*s);
		if (!ft_is_num(*s) && (g_error.id = 11))
			return (1);
		free(*s);
		*s = ft_strnew(0);
	}
	return (0);
}

static char		*fill_type(char *type, char *s)
{
	char	*tmp;

	if (*s == DIRECT_CHAR)
	{
		*type = T_DIR;
		tmp = ft_strdup(s + 1);
		free(s);
		return (tmp);
	}
	else if (*s == 'r' && ft_res_is_true(s + 1, ft_isdigit))
	{
		*type = T_REG;
		tmp = ft_strdup(s + 1);
		free(s);
		return (tmp);
	}
	*type = T_IND;
	return (s);
}

char			check_arg(char **arg, char *type, int *value)
{
	char	*new;

	new = ft_strtrim(*arg);
	free(*arg);
	*arg = fill_type(type, new);
	if (check_value(value, arg))
		return (1);
	return (0);
}

char			parse_args(char *line, t_tokens *new)
{
	char	**args;
	int		n_arg;

	crop_comment(line);
	n_arg = 0;
	args = ft_strsplit(line, SEPARATOR_CHAR);
	while (args[n_arg])
	{
		if (n_arg > new->command->arg_q && (g_error.id = 12))
			return (free_two_dim_array(args));
		if (check_arg(&args[n_arg], &new->types[n_arg], &new->values[n_arg]))
			return (free_two_dim_array(args));
		n_arg++;
	}
	free_bad_args(new, n_arg, args);
	free(args);
	if (n_arg != new->command->arg_q && (g_error.id = 12))
		return (1);
	if ((!(new->types[0] & new->command->arg_type[0]) ||
		(!(new->types[1] & new->command->arg_type[1]) && n_arg > 1) ||
		(!(new->types[2] & new->command->arg_type[2]) && n_arg > 2)) &&
		(g_error.id = 11))
		return (1);
	return (0);
}
