/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:07:54 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:57:48 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	char	*ret;
	char	*buf;

	buf = (char *)s;
	ret = NULL;
	while (*buf != '\0')
	{
		if (*buf == (char)c)
			ret = buf;
		buf++;
	}
	if (c == '\0')
		return (buf);
	return (ret);
}
