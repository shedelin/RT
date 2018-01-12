/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:07:14 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/23 16:06:48 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_o(va_list ap)
{
	int				nb_put;
	unsigned int	nb;
	unsigned int	res;
	long			i;

	nb = va_arg(ap, unsigned int);
	i = 1;
	res = 0;
	while (nb)
	{
		res += (nb % 8) * i;
		nb /= 8;
		i *= 10;
	}
	nb_put = 0;
	nb_put += ft_putstr_i(ft_itoa(res));
	return (nb_put);
}

int					ft_u(va_list ap)
{
	int				nb_put;
	unsigned int	k;

	k = va_arg(ap, unsigned int);
	nb_put = 0;
	nb_put += ft_putstr_i(ft_uitoa(k));
	return (nb_put);
}

int					ft_s(va_list ap)
{
	int				nb_put;
	char			*str;

	nb_put = 0;
	str = va_arg(ap, char *);
	if (!str)
		nb_put += ft_putstr_i("(null)");
	else
		nb_put += ft_putstr_i(str);
	return (nb_put);
}

int					ft_c(va_list ap)
{
	int				nb_put;

	nb_put = 0;
	nb_put += ft_putchar_i(va_arg(ap, int));
	return (nb_put);
}

int					ft_d(va_list ap)
{
	int				nb_put;

	nb_put = 0;
	nb_put += ft_putstr_i(ft_itoa(va_arg(ap, int)));
	return (nb_put);
}
