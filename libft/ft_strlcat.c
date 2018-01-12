/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:07:00 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:50:53 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	zsrc;
	size_t	zdst;
	int		i;

	i = 0;
	zsrc = ft_strlen(src);
	zdst = ft_strlen(dst);
	if (size < zdst && zsrc + zdst + 1 > sizeof(dst))
		return (size + zsrc);
	while (src[i] != '\0' && size - 1 > zdst + i)
	{
		dst[zdst + i] = src[i];
		i++;
	}
	dst[zdst + i] = '\0';
	return (zdst + zsrc);
}
