/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:17:34 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:55:26 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	int		i;

	if (n == 0)
		return (s1);
	i = -1;
	while (++i < (int)n && s2[i] != '\0')
		s1[i] = s2[i];
	while (i < (int)n)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
