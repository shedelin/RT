/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:38:17 by caupetit          #+#    #+#             */
/*   Updated: 2014/01/13 18:37:55 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cpcont;

	new = NULL;
	cpcont = NULL;
	if (content)
	{
		if (!(cpcont = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(cpcont, content, content_size);
	}
	else
	{
		cpcont = NULL;
		content_size = 0;
	}
	if (!(new = (void *)malloc(sizeof(t_list))))
	{
		ft_memdel(&cpcont);
		return (NULL);
	}
	new->content = cpcont;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
