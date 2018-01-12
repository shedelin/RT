/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:30:28 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:59:02 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	zs;

	zs = ft_strlen(s + start);
	s1 = ft_strnew(zs);
	if (!s1 && zs > len)
		return (NULL);
	ft_strncpy(s1, &s[start], len);
	return (s1);
}
