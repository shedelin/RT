/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:30:18 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:32:07 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*s1t;
	unsigned char	*s2t;
	int				i;

	s1t = s1;
	s2t = (unsigned char *)s2;
	i = -1;
	while (++i < (int)n)
	{
		if ((s1t[i] = s2t[i]) == (char)c)
			return (&s1t[i + 1]);
	}
	return ((void *)NULL);
}
