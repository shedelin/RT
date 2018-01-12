/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:37:56 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 15:09:34 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		pln_get_hit(t_ray *r, void *obj)
{
	double	dir;
	double	t;
	t_pln	*pln;

	pln = (t_pln *)obj;
	dir = pln->dir.x * r->dir.x + pln->dir.y * r->dir.y;
	dir += pln->dir.z * r->dir.z;
	t = MULT(pln->dir.x, -r->or.x);
	t += MULT(pln->dir.y, -r->or.y);
	t += MULT(pln->dir.z, -r->or.z);
	t = (t / dir);
	if (t > 0)
		return (t);
	return (0);
}

double		pln_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam)
{
	double	angle;
	t_vect	hit_norm;

	(void)rcam;
	obj->ray.norm = ((t_pln *)obj->obj)->dir;
	hit_norm = obj->ray.norm;
	rot_apply(&hit_norm, obj->invrot.z);
	rot_apply(&hit_norm, obj->invrot.x);
	rot_apply(&hit_norm, obj->invrot.y);
	obj->ray.rnorm = hit_norm;
	angle = DOT((*(t_pln *)obj->obj).dir, spot->dir);
	return (angle);
}
