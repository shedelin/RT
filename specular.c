/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 15:34:33 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/27 15:01:22 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

t_ccolor		light_get_specular(t_spot *spot, t_obj *obj)
{
	t_vect		refl;
	double		angle;
	t_ccolor	ccol;
	t_ray		spotray;

	spotray = light_get_dir(spot->ray, obj, &obj->ray.rhit);
	refl = vect_get_reflected(obj->ray.norm, obj->ray.dir);
	angle = -DOT(refl, spotray.dir);
	if (angle < 0)
		angle = 0;
	else
		angle = pow(angle, obj->mat.shin);
	ccol.r = angle * spot->ccol.r * obj->mat.spec;
	ccol.g = angle * spot->ccol.g * obj->mat.spec;
	ccol.b = angle * spot->ccol.b * obj->mat.spec;
	return (ccol);
}
