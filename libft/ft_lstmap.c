/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:23:20 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 18:16:58 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_dellist(t_list **lst)
{
	if (*lst)
	{
		ft_dellist(&(*lst)->next);
		free((*lst)->content);
		(*lst)->content = NULL;
		free(*lst);
		*lst = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*list;

	list = NULL;
	while (lst)
	{
		elem = NULL;
		elem = ft_lstnew(f(lst), sizeof(f(lst)));
		if (!elem)
		{
			ft_dellist(&list);
			return (list);
		}
		ft_lstadd(&list, elem);
		lst = lst->next;
		ft_memdel((void *)&elem->content);
		ft_memdel((void *)&elem);
	}
	return (list);
}
