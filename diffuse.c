/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:26:57 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/26 15:14:48 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

static double	diffuse_get_angle(t_ray *spot, t_obj *obj)
{
	static double	(*light_angle[])(t_ray *, t_obj *, t_ray *) =

	{
	&sphr_get_light_angle,
	&pln_get_light_angle,
	&cyl_get_light_angle,
	&cone_get_light_angle,
	&ellips_get_light_angle
	};
	return (light_angle[obj->type](spot, obj, &obj->ray));
}

t_ccolor		light_get_diffuse(t_spot *spot, t_obj *obj, double coef2)
{
	t_ccolor	col;
	double		coef;
	t_ray		spotray;

	spotray = light_get_dir(spot->ray, obj, &obj->ray.rhit);
	coef = diffuse_get_angle(&spotray, obj) / 2;
	coef *= coef2;
	if (coef < 0)
		coef = 0;
	coef = coef * coef * 2.3;
	coef += 0.03;
	if (coef > 1)
		coef = 1;
	col.r = obj->mat.diff.r * coef * spot->ccol.r;
	col.g = obj->mat.diff.g * coef * spot->ccol.g;
	col.b = obj->mat.diff.b * coef * spot->ccol.b;
	return (col);
}
