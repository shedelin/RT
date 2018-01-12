/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:33:12 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/22 17:03:16 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putstr(char const *s)
{
	int		i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(1, s, i);
}
