/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:35:44 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 15:41:06 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"
#include "libft.h"

void		lex_lst_put(t_llex **l_lex)
{
	t_llex	*tmp;
	int		i;

	tmp = *l_lex;
	i = 1;
	ft_printf("l_lex:\n");
	while (tmp)
	{
		ft_printf("%d: type: %d, str: %s\n", i, tmp->type, tmp->str);
		i++;
		tmp = tmp->next;
	}
}

void		lex_lst_del(t_llex **l_lex)
{
	t_llex	*tmp;
	t_llex	*tmp2;

	tmp = *l_lex;
	while (tmp)
	{
		ft_strdel(&tmp->str);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

t_llex		*lex_lst_new(t_laut *aut)
{
	t_llex	*new;

	if (!(new = (t_llex *)malloc(sizeof(t_llex))))
		return (NULL);
	new->type = aut->status;
	if (!(new->str = ft_strdup(aut->buf)))
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void		lex_lst_add(t_llex **l_lex, t_llex *new)
{
	t_llex	*tmp;

	tmp = *l_lex;
	if (!tmp)
	{
		*l_lex = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
