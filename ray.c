/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:37:56 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/11 19:46:38 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		get_target(t_pos *t, t_cam *c, int x, int y)
{
	t_vect		rt;
	t_vect		up;
	double		xmove;
	double		ymove;

	xmove = c->xind * x;
	ymove = c->yind * y;
	rt.x = c->view.rtvect.x * xmove;
	rt.y = c->view.rtvect.y * xmove;
	rt.z = c->view.rtvect.z * xmove;
	up.x = c->view.upvect.x * ymove;
	up.y = c->view.upvect.y * ymove;
	up.z = c->view.upvect.z * ymove;
	t->x = c->view.upleft.x + rt.x - up.x;
	t->y = c->view.upleft.y + rt.y - up.y;
	t->z = c->view.upleft.z + rt.z - up.z;
}

void			ray_init(t_ray *r, t_cam *cam, int x, int y)
{
	t_pos	target;

	r->t = 1000000.0;
	pos_get(&r->or, cam->pos.x, cam->pos.y, cam->pos.z);
	get_target(&target, cam, x, y);
	vect_get_from_points(&r->dir, r->or, target);
	vect_normalise(&r->dir, 0);
}
