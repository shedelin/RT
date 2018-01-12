/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_same.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:35:44 by caupetit          #+#    #+#             */
/*   Updated: 2013/12/26 16:45:06 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_same(char *s1, char const *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (tmp);
}
