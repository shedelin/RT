/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:05:54 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/01 15:39:47 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	char	*bt;
	char	ct;

	bt = (char *)b;
	ct = (char)c;
	while (len--)
		bt[len] = ct;
	return (b);
}
