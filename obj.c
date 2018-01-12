/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:37:56 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/24 19:38:01 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"
#include "rtv1.h"

int			obj_set_color(t_obj *obj, t_pos pos, int min, int max)
{
	if (pos.x < min || pos.x > max || pos.y < min || pos.y > max)
		return (error(ERR_VAL_VAL, OBJ, OBJ_COLOR));
	if (pos.z < min || pos.z > max)
		return (error(ERR_VAL_VAL, OBJ, OBJ_COLOR));
	obj->color.r = (double)pos.x;
	obj->color.g = (double)pos.y;
	obj->color.b = (double)pos.z;
	return (1);
}

static void	ft_obj_del_rot(t_rot *rot)
{
	int	i;

	i = 0;
	while (i < 3 && rot->x && rot->y && rot->z)
	{
		free(rot->x[i]);
		free(rot->y[i]);
		free(rot->z[i]);
		i++;
	}
	free(rot->x);
	free(rot->y);
	free(rot->z);
}

void		ft_obj_del(t_obj **obj)
{
	t_obj	*tmp;
	t_obj	*tmp1;

	tmp = *obj;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		ft_obj_del_rot(&tmp1->rot);
		ft_obj_del_rot(&tmp1->invrot);
		if (tmp1->obj)
			free(tmp1->obj);
		tmp1->obj = NULL;
		free(tmp1);
		tmp1 = NULL;
	}
}

void		ft_obj_add(t_obj **l_obj, t_obj *new)
{
	t_obj	*tmp;

	if (!*l_obj)
		*l_obj = new;
	else
	{
		tmp = *l_obj;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
