/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:59:04 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:38:17 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "rtv1.h"
#include "libft.h"

int			is_vertex(t_llex *lst)
{
	int		len;
	t_llex	*tmp;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		len++;
		if (len > 1 && len <= 4)
		{
			if (tmp->type != _num || ft_strlen(tmp->str) > 6)
				return (error(ERR_VERT_INT, lst->str, NULL));
		}
		if (len == 5 && tmp->type != _comment)
			return (error(ERR_PARS_ARG, lst->str, NULL));
		tmp = tmp->next;
	}
	if (len < 4)
		return (error(ERR_VERT_FEW, lst->str, NULL));
	if (len > 5)
		return (error(ERR_VERT_MANY, lst->str, NULL));
	return (1);
}

int			is_value(t_llex *lst)
{
	if (!lst->next || lst->next->type != _num)
		return (error(ERR_VAL_INT, lst->str, NULL));
	if (lst->next->next && lst->next->next->type != _comment)
		return (error(ERR_PARS_ARG, lst->str, NULL));
	return (1);
}

int			is_token(t_llex *lst)
{
	if (lst->next && lst->next->type != _comment)
		return (error(ERR_PARS_ARG, lst->str, NULL));
	return (1);
}

void		ft_get_scene_init(int *r, char **s, t_saut *a)
{
	int		i;

	i = -1;
	*r = 1;
	*s = NULL;
	while (++i < PARS_TOK_NB)
		a->done[i] = 0;
	a->status = _start;
}
