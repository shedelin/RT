/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:28:30 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:30:57 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
