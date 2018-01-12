/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:53:39 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/25 17:41:47 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	zs2;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	zs2 = ft_strlen(s2);
	while (*s1 != '\0')
	{
		i = 0;
		while (s1[i] == s2[i] && s1[i] != '\0' && i < (int)zs2)
			i++;
		if (i == (int)zs2)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
