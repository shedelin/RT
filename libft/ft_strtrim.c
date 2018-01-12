/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:36:12 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:59:29 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char			*s1;
	size_t			zs;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	zs = ft_strlen(s);
	while (ft_isspace(s[i]) && s[i])
		i++;
	while (ft_isspace(s[zs - 1]) && zs > i)
		zs--;
	s1 = ft_strsub(s, i, zs - i);
	return (s1);
}
