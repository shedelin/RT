/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:23:29 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:52:50 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	int		i;

	i = 0;
	s1 = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		s1[i] = f(s[i]);
		i++;
	}
	return (s1);
}
