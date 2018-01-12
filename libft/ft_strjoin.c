/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:34:34 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/28 17:19:06 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	zdst;

	s = NULL;
	zdst = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s = ft_strnew(zdst)))
		return (NULL);
	ft_strcpy(s, s1);
	if (s2)
		ft_strlcat(s, s2, zdst);
	return (s);
}
