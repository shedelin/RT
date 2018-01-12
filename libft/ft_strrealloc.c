/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 12:43:06 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/11 14:27:41 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_strrealloc(char **str, size_t size)
{
	char		*tmp;

	tmp = NULL;
	if (!(*str))
	{
		if (!(*str = ft_strnew(size)))
			return (0);
		return (1);
	}
	if (!(tmp = ft_strdup(*str)))
		return (0);
	ft_strdel(str);
	if (!(*str = ft_strnew(size)))
	{
		ft_strdel(&tmp);
		return (0);
	}
	*str = ft_strncpy(*str, tmp, size);
	ft_strdel(&tmp);
	return (1);
}
