/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:56:58 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:46:08 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	zs1;
	size_t	zs2;
	size_t	z;

	zs1 = ft_strlen((char *)s1);
	zs2 = ft_strlen((char *)s2);
	if (zs1 < zs2)
		z = zs2;
	else
		z = zs1;
	return (ft_memcmp((char *)s1, (char *)s2, z));
}
