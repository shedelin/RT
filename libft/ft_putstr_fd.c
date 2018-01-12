/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:48:54 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/22 17:11:07 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
}
