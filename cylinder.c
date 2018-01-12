/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:20:01 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 15:10:22 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		cyl_get_hit(t_ray *r, void *obj)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_cyl	*cyl;

	cyl = (t_cyl *)obj;
	a = SQUARE(r->dir.x) + SQUARE(r->dir.z);
	b = (MULT(r->dir.x, r->or.x));
	b += (MULT(r->dir.z, r->or.z));
	b *= 2;
	c = SQUARE(r->or.x);
	c += SQUARE(r->or.z);
	c -= SQUARE(cyl->rad);
	det = SQUARE(b) - (4 * a * c);
	return (res_eq(det, a, b));
}

double		cyl_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam)
{
	double	angle;
	t_vect	hit_norm;
	t_pos	or;

	(void)obj;
	pos_get(&or, 0, rcam->hit.y, 0);
	angle = 1;
	vect_get_from_points(&hit_norm, or, rcam->hit);
	vect_normalise(&hit_norm, 0);
	obj->ray.norm = hit_norm;
	rot_apply(&hit_norm, obj->invrot.y);
	rot_apply(&hit_norm, obj->invrot.x);
	rot_apply(&hit_norm, obj->invrot.z);
	obj->ray.rnorm = hit_norm;
	angle = DOT(spot->dir, obj->ray.norm);
	return (-angle);
}
