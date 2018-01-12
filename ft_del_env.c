/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin <cmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:48:05 by cmartin           #+#    #+#             */
/*   Updated: 2014/03/27 12:59:43 by cmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>

void	ft_spot_del(t_spot **spot)
{
	t_spot	*tmp;

	tmp = *spot;
	while (tmp)
	{
		tmp = tmp->next;
		free(*spot);
		*spot = NULL;
		*spot = tmp;
	}
}

void	ft_del(t_env *e)
{
	ft_obj_del(&e->l_obj);
	ft_spot_del(&e->l_spot);
	e->l_obj = NULL;
	e->l_spot = NULL;
}

void	reset_draw(t_env *e, int selected)
{
	ft_del(e);
	e->selected_button = selected;
	e->draw = 0;
	e->status = 1;
}
