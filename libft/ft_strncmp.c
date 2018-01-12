/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:58:47 by caupetit          #+#    #+#             */
/*   Updated: 2014/01/07 13:17:39 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*ps1;
	char	*ps2;

	ps1 = (char *)s1;
	ps2 = (char *)s2;
	while (n > 0 && *ps1 != '\0' && *ps2 != '\0')
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
		n--;
	}
	if (*ps1 != *ps2)
		return (*ps1 - *ps2);
	return (0);
}
