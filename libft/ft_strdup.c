/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:23:47 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:47:28 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;

	if ((char *)s1 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	s2 = ft_strnew(size + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memmove(s2, s1, size + 1);
	return (s2);
}
