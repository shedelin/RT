/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:35:11 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:39:07 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*s3;

	s3 = ft_memalloc(n);
	if (s3 == NULL)
		return (s1);
	ft_memcpy(s3, (void *)s2, n);
	ft_memcpy(s1, s3, n);
	ft_memdel(&s3);
	return (s1);
}
