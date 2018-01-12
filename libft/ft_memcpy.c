/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:28:05 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/22 11:25:42 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*s1t;
	char	*s2t;

	s1t = (char *)s1;
	s2t = (char *)s2;
	while (n--)
		s1t[n] = s2t[n];
	return (s1);
}
