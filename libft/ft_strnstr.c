/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:55:17 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:57:01 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (*s1 != '\0' && n > 0)
	{
		while (s1[i] == s2[i] && i < n)
		{
			if (s2[i] == '\0')
				return ((char *)s1);
			i++;
		}
		if (s2[i] == '\0')
			return ((char *)s1);
		s1++;
		n--;
		i = 0;
	}
	return (NULL);
}
