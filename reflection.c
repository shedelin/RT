/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:23:34 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/27 15:03:18 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		view_get_mini(t_cam *cam, double size, t_obj *obj)
{
	t_vect	rdir;

	rdir = obj->ray.dir;
	rot_apply(&rdir, obj->invrot.z);
	rot_apply(&rdir, obj->invrot.x);
	rot_apply(&rdir, obj->invrot.y);
	cam->pos = obj->ray.rhit;
	cam->dir = vect_get_reflected(obj->ray.rnorm, rdir);
	cam->view.dist = 1;
	cam->view.width = size;
	cam->view.height = size;
	cam->xind = cam->view.width / 5;
	cam->yind = cam->view.height / 5;
	vect_get(&cam->view.upvect, 0, 1, 0);
	view_get(cam);
}

t_ccolor		fresnel(t_ccolor col1, t_ccolor col2, t_obj *obj)
{
	double		fresnel;

	fresnel = -DOT(obj->ray.norm, obj->ray.dir);
	if (fresnel < 0)
		fresnel = -fresnel;
	fresnel = fresnel + (1 - fresnel) * obj->mat.refl;
	fresnel *= obj->mat.refl;
	col1.r = col1.r * (1 - fresnel) + col2.r * fresnel;
	col1.g = col1.g * (1 - fresnel) + col2.g * fresnel;
	col1.b = col1.b * (1 - fresnel) + col2.b * fresnel;
	return (col1);
}

static t_obj	reflection_get_object(t_obj obj, t_obj refobj)
{
	obj.ray = refobj.ray;
	obj.ray.or = sub_vect(obj.ray.or, &obj.or);
	rot_apply(&obj.ray.or, obj.rot.y);
	rot_apply(&obj.ray.or, obj.rot.x);
	rot_apply(&obj.ray.or, obj.rot.z);
	rot_apply(&obj.ray.dir, obj.rot.y);
	rot_apply(&obj.ray.dir, obj.rot.x);
	rot_apply(&obj.ray.dir, obj.rot.z);
	return (obj);
}

static t_ccolor	diffuse_reflection(t_obj *l_obj, t_obj refobj, t_env *e, int i)
{
	t_ccolor	ccol;
	t_obj		o;
	t_obj		reflobj;

	ccol = ccolor_get(0, 0, 0);
	o.obj = 0;
	o.ray.t = MAXT;
	while (l_obj)
	{
		if (!(l_obj->obj == refobj.obj))
		{
			reflobj = reflection_get_object(*l_obj, refobj);
			reflobj.ray.t = get_hit(&reflobj.ray, l_obj);
			if (reflobj.ray.t > 0 && reflobj.ray.t < o.ray.t)
				o = reflobj;
		}
		l_obj = l_obj->next;
	}
	if (o.obj)
	{
		obj_get_hit(&o);
		ccol = light_get(e, &o, i);
	}
	return (ccol);
}

t_ccolor		light_get_reflection(t_env *e, t_obj *obj, int i)
{
	t_obj		reflobj;
	t_ccolor	ccol;
	t_cam		cam;
	int			rays;

	ccol = ccolor_get(0, 0, 0);
	rays = 0;
	i--;
	view_get_mini(&cam, obj->mat.sblur, obj);
	reflobj.obj = obj->obj;
	reflobj.ray.t = MAXT;
	while (rays < 5)
	{
		ray_init(&reflobj.ray, &cam, rays, rays);
		ccol = add_ccolor(diffuse_reflection(e->l_obj, reflobj, e, i), ccol);
		rays++;
	}
	ccol = ccolor_get_double(ccol.r / 10, ccol.g / 10, ccol.b / 10);
	ccol.r *= obj->mat.diff.r * obj->mat.spec;
	ccol.g *= obj->mat.diff.g * obj->mat.spec;
	ccol.b *= obj->mat.diff.b * obj->mat.spec;
	return (ccol);
}
