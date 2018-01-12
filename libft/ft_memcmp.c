/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:03:13 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:34:00 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1t;
	unsigned char	*s2t;
	int				i;

	i = 0;
	s1t = (unsigned char *)s1;
	s2t = (unsigned char *)s2;
	while (i < (int)n && n != 0)
	{
		if (s1t[i] != s2t[i])
			return (s1t[i] - s2t[i]);
		i++;
	}
	return (0);
}
