/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:37:56 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 15:08:10 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		sphr_get_hit(t_ray *r, void *obj)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_sphr	*sphr;

	sphr = (t_sphr *)obj;
	a = SQUARE(r->dir.x) + SQUARE(r->dir.y) + SQUARE(r->dir.z);
	b = (MULT(r->dir.x, r->or.x));
	b += (MULT(r->dir.y, r->or.y));
	b += (MULT(r->dir.z, r->or.z));
	b *= 2;
	c = SQUARE(r->or.x);
	c += SQUARE(r->or.y);
	c += SQUARE(r->or.z);
	c -= SQUARE(sphr->rad);
	det = SQUARE(b) - (4 * a * c);
	return (res_eq(det, a, b));
}

double		sphr_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam)
{
	t_vect	hit_norm;
	double	angle;

	(void)obj;
	angle = 0;
	hit_norm = rcam->hit;
	vect_normalise(&hit_norm, 0);
	obj->ray.norm = hit_norm;
	rot_apply(&hit_norm, obj->invrot.z);
	rot_apply(&hit_norm, obj->invrot.x);
	rot_apply(&hit_norm, obj->invrot.y);
	obj->ray.rnorm = hit_norm;
	angle = DOT(spot->dir, obj->ray.norm);
	return (-angle);
}
