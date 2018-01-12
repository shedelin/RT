/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:25:14 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:53:17 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	i = 0;
	s1 = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	return (s1);
}
