/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:25:50 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/27 14:55:30 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "rtv1.h"
#include "libft.h"

static int		light_get_shadow(t_ray *spot, t_obj *o, t_obj *l)
{
	t_ray		tmpray;
	double		t;

	t = MAG(sub_vect(spot->or, &o->ray.rhit));
	while (l)
	{
		if (l->obj != o->obj)
		{
			tmpray = light_get_dir(*spot, l, &o->ray.rhit);
			tmpray.t = get_hit(&tmpray, l);
			if (tmpray.t > 0.0 && tmpray.t < t)
				return (1);
		}
		l = l->next;
	}
	return (0);
}

t_ray			light_get_dir(t_ray spot, t_obj *obj, t_pos *hit)
{
	vect_get_from_points(&spot.dir, spot.or, *hit);
	vect_normalise(&spot.dir, 0);
	spot.or = sub_vect(spot.or, &obj->or);
	rot_apply((t_vect *)&spot.or, obj->rot.y);
	rot_apply((t_vect *)&spot.or, obj->rot.x);
	rot_apply((t_vect *)&spot.or, obj->rot.z);
	rot_apply((t_vect *)&spot.dir, obj->rot.y);
	rot_apply((t_vect *)&spot.dir, obj->rot.x);
	rot_apply((t_vect *)&spot.dir, obj->rot.z);
	return (spot);
}

t_ccolor		light_get(t_env *e, t_obj *chit, int depth)
{
	t_ccolor	ccol;
	t_spot		*tmp;
	int			shad;
	t_ccolor	specccol;

	tmp = e->l_spot;
	ccol = ccolor_get(0, 0, 0);
	specccol = ccolor_get(0, 0, 0);
	while (tmp)
	{
		shad = light_get_shadow(&tmp->ray, chit, e->l_obj);
		if (!shad)
			ccol = add_ccolor(light_get_diffuse(tmp, chit, 1), ccol);
		else
			ccol = add_ccolor(light_get_diffuse(tmp, chit, 0.5), ccol);
		if (!shad)
			specccol = add_ccolor(light_get_specular(tmp, chit), specccol);
		tmp = tmp->next;
	}
	if (chit->mat.refl != 1 && depth > 0)
		ccol = fresnel(light_get_reflection(e, chit, depth), ccol, chit);
	ccol = add_ccolor(specccol, ccol);
	ccolor_normalise(&ccol);
	return (ccol);
}
