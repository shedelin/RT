/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 16:15:16 by caupetit          #+#    #+#             */
/*   Updated: 2014/01/07 13:17:15 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_getsize(unsigned int n)
{
	int		i;

	i = 0;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (++i);
}

static char	*ft_reverse(char *s)
{
	char	*s1;
	int		zs;
	int		i;

	i = 0;
	zs = ft_strlen(s);
	s1 = ft_strdup(s);
	if (*s == '-')
		i++;
	while (s[i])
	{
		s[i] = s1[zs - 1];
		i++;
		zs--;
	}
	return (s);
}

char		*ft_uitoa(unsigned int n)
{
	char	*s;
	size_t	z;
	int		i;

	i = 0;
	z = ft_getsize(n);
	s = ft_strnew(ft_getsize(n));
	if (!s)
		return (NULL);
	while (i < (int)z)
	{
		s[i++] = n % 10 + '0';
		n = n / 10;
	}
	s[++i] = n % 10 + '0';
	s = ft_reverse(s);
	return (s);
}
