/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:53:52 by caupetit          #+#    #+#             */
/*   Updated: 2014/01/01 21:08:14 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_strtab_del(char ***pt)
{
	int		i;

	if (!*pt)
		return ;
	i = -1;
	while ((*pt)[++i])
		ft_strdel(&(*pt)[i]);
	if (*pt)
		free(*pt);
	*pt = NULL;
}
