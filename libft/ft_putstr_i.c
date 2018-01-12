/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:41:32 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/30 16:41:35 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			ft_putstr_i(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}
