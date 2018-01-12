/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:33:34 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/22 11:25:29 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*st;
	int		i;

	st = (char *)s;
	i = -1;
	while (++i < (int)n && n != 0)
	{
		if (st[i] == (unsigned char)c)
			return ((void *)&st[i]);
	}
	return (NULL);
}
