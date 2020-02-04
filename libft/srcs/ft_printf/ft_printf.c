/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:14 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:51:16 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	free_spec(t_spec *spec, int count)
{
	int		i;

	i = -1;
	while (++i < count)
		free(spec[i].cont);
	free(spec);
}

int		ft_printf(const char *format, ...)
{
	int		count;
	int		len;
	t_spec	*spec;
	va_list	ap;

	len = ft_strlen(format);
	count = count_spec(format, NULL);
	spec = NULL;
	if (count && !(spec = (t_spec*)malloc(sizeof(t_spec) * count)))
		exit(0);
	if (count)
	{
		count_spec(format, spec);
		set_spec(spec, count);
		va_start(ap, format);
		set_cont(ap, spec, count);
		va_end(ap);
	}
	len = print_f(format, spec, len, count);
	if (count)
		free_spec(spec, count);
	return (len);
}
