/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:26:25 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/27 18:05:12 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rtv1.h"
#include "mlx.h"

void			obj_get_hit(t_obj *o)
{
	o->ray.hit.x = o->ray.or.x + o->ray.dir.x * o->ray.t;
	o->ray.hit.y = o->ray.or.y + o->ray.dir.y * o->ray.t;
	o->ray.hit.z = o->ray.or.z + o->ray.dir.z * o->ray.t;
	o->ray.rhit = o->ray.hit;
	rot_apply(&o->ray.rhit, o->invrot.z);
	rot_apply(&o->ray.rhit, o->invrot.x);
	rot_apply(&o->ray.rhit, o->invrot.y);
	o->ray.rhit = add_vect(o->ray.rhit, &o->or);
}

static void		ft_set_img(t_env *e, int x, int y, int color)
{
	unsigned int	col;
	int				*cpy;

	cpy = (int *)e->img.pxl;
	col = mlx_get_color_value(e->mlx, color);
	cpy[y * (e->img.ln / 4) + x] = col;
}

double			get_hit(t_ray *r, t_obj *obj)
{
	static double	(*ft_hit[])(t_ray *, void *) =

	{
	&sphr_get_hit,
	&pln_get_hit,
	&cyl_get_hit,
	&cone_get_hit,
	&ellips_get_hit
	};
	return (ft_hit[obj->type](r, obj->obj));
}

void			ft_draw_pix(int x, int y, t_env *e)
{
	t_obj		*o;
	t_obj		*tmp;
	int			color;

	color = COL(0, 0, 0);
	o = NULL;
	tmp = e->l_obj;
	while (tmp)
	{
		tmp->ray.t = MAXT;
		ray_init(&tmp->ray, &tmp->cam, x, y);
		tmp->ray.t = get_hit(&tmp->ray, tmp);
		if (tmp->ray.t > 0 && (!o || tmp->ray.t < o->ray.t))
			o = tmp;
		tmp = tmp->next;
	}
	if (o)
	{
		obj_get_hit(o);
		color = color_pixel_get(e, o, DEPTH);
	}
	ft_set_img(e, x, y, color);
}
