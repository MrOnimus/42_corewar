/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgarth-o <kgarth-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:25 by kgarth-o          #+#    #+#             */
/*   Updated: 2019/10/29 13:51:26 by kgarth-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_f(const char *str, t_spec *spec, int len, int count)
{
	if (spec)
	{
		while (count--)
		{
			ft_putstr_chr(str, spec->pos);
			ft_putstr(spec->cont);
			if (SPEC == 'c' && NEG)
			{
				++len;
				ft_putchar(CONT[ft_strlen(CONT)]);
			}
			len -= spec->del;
			len += ft_strlen(spec->cont);
			str += spec->del + ft_strlen_chr(str, spec->pos);
			spec++;
		}
		ft_putstr(str);
		return (len);
	}
	else
	{
		write(1, str, len);
		return (len);
	}
}
