/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:54:16 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 18:51:01 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_get_arg_opt(char opt, va_list ap)
{
	int			i;
	int			nb_put;
	static int	opt_tab[NB_OPT] = {'d', 'i', 'c', 's', 'u', 'o'};
	static t_f	func[NB_OPT] = {ft_d, ft_d, ft_c, ft_s, ft_u, ft_o};

	nb_put = 0;
	i = -1;
	while (++i < NB_OPT)
	{
		if (opt_tab[i] == opt)
			nb_put += func[i](ap);
	}
	return (nb_put);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			nb_put;

	i = -1;
	nb_put = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
			nb_put += ft_putchar_i(format[i]);
		if (format[i] == '%')
		{
			i++;
			nb_put += ft_get_arg_opt(format[i], ap);
		}
	}
	va_end(ap);
	return (nb_put);
}
