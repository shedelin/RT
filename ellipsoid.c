/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 12:42:37 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/26 15:26:35 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	ellips_get_light:
**	Founds the distance between the camera and an intersection on an ellipsoid
**	Ellipsoid equation : x²/a² + y²/b² + z²/c² - 1 = 0
**	where x, y, c are the coordinates of a point relative to the center
**	and a, b, c half the lenghts of its axes.
**	Vector form: M = [ 1/a  1/b  1/c ]
**	Then for any point P = (x,y,z) we have PM = (x/a  y/b  z/c)
**	We can write the ellipsoid equation as (PM - CM) • (PM - CM) - 1 = 0
**	where C is its center
**	Replacing P with the ray equation P = Po + t*v, we got
**	(Po*M + t*v*M - C*M) • (Po*M + t*v*M - C*M) - 1 = 0
**	Let v1 = v*M and let P1 = Po*M - C*M
**	We got (P1 + t*v1) • (P1 + t*v1) - 1 = |P1|² + 2*t*P1 • v1 t²*|v1|² - 1
**	which we can resolve with a quadric formula
**	At² + Bt + C = 0
**	A = |v1|²
**	B = 2 * P1 • v1
**	C = |P1|² - 1
**	We can now find ∆ and resolve the equation
*/

/*
** ellips_get_light_angle:
** This founds the illumination coefficent of a point by the dot product of
** the light vector and the normal of the surface
** Calculate the coordinates of the point relative to the center of the
** ellipsoid
** Calculate the normal vector by doing a partial derivation of each direction
** ∂f/∂x = 2x/a² , ∂f/∂y = 2y/b² , ∂f/∂z = 2z/c²
** Calculate the vector from the light to the point
** Normalize the two vectors and do the dot product
*/

double		ellips_get_hit(t_ray *r, void *obj)
{
	t_vect			v1;
	t_vect			p1;
	t_det			n;
	t_ellips		*e;

	e = (t_ellips *)obj;
	p1.x = r->or.x * (1.0 / e->size.x);
	p1.y = r->or.y * (1.0 / e->size.y);
	p1.z = r->or.z * (1.0 / e->size.z);
	v1.x = r->dir.x * (1.0 / e->size.x);
	v1.y = r->dir.y * (1.0 / e->size.y);
	v1.z = r->dir.z * (1.0 / e->size.z);
	n.a = DOT(v1, v1);
	n.b = 2 * DOT(v1, p1);
	n.c = DOT(p1, p1) - 1;
	n.det = (n.b * n.b) - (4 * n.a * n.c);
	return (res_eq(n.det, n.a, n.b));
}

double		ellips_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam)
{
	t_vect		hit_norm;
	t_ellips	*e;

	e = (t_ellips *)obj->obj;
	hit_norm = rcam->hit;
	hit_norm.x = 2.0 * hit_norm.x / SQUARE(e->size.x);
	hit_norm.y = 2.0 * hit_norm.y / SQUARE(e->size.y);
	hit_norm.z = 2.0 * hit_norm.z / SQUARE(e->size.z);
	vect_normalise(&hit_norm, 0);
	obj->ray.norm = hit_norm;
	rot_apply(&hit_norm, obj->invrot.z);
	rot_apply(&hit_norm, obj->invrot.x);
	rot_apply(&hit_norm, obj->invrot.y);
	obj->ray.rnorm = hit_norm;
	return (-DOT(spot->dir, obj->ray.norm));
}
