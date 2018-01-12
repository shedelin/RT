/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:30:24 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/24 18:54:19 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		view_get_upleft(t_pos *p, t_cam *c)
{
	double		transup;
	double		transrt;

	transup = c->view.upvect.x * (c->view.height / 2);
	transrt = c->view.rtvect.x * (c->view.width / 2);
	p->x = c->pos.x + ((c->dir.x * c->view.dist) + transup) - transrt;
	transup = c->view.upvect.y * (c->view.height / 2);
	transrt = c->view.rtvect.y * (c->view.width / 2);
	p->y = c->pos.y + ((c->dir.y * c->view.dist) + transup) - transrt;
	transup = c->view.upvect.z * (c->view.height / 2);
	transrt = c->view.rtvect.z * (c->view.width / 2);
	p->z = c->pos.z + ((c->dir.z * c->view.dist) + transup) - transrt;
}

void			view_get(t_cam *cam)
{
	vect_cros(&cam->view.rtvect, cam->view.upvect, cam->dir);
	vect_cros(&cam->view.upvect, cam->dir, cam->view.rtvect);
	view_get_upleft(&cam->view.upleft, cam);
}

void			cam_obj_set(t_env *e, t_obj *o)
{
	o->cam = e->cam;
	o->cam.pos = sub_vect(o->cam.pos, &o->or);
	rot_apply((t_vect *)&o->cam.pos, o->rot.y);
	rot_apply((t_vect *)&o->cam.pos, o->rot.x);
	rot_apply((t_vect *)&o->cam.pos, o->rot.z);
	rot_apply(&o->cam.dir, o->rot.y);
	rot_apply(&o->cam.dir, o->rot.x);
	rot_apply(&o->cam.dir, o->rot.z);
	vect_normalise(&o->cam.dir, 0);
	o->cam.view.upleft = e->cam.view.upleft;
	rot_apply((t_vect *)&o->cam.view.upvect, o->rot.y);
	rot_apply((t_vect *)&o->cam.view.upvect, o->rot.x);
	rot_apply((t_vect *)&o->cam.view.upvect, o->rot.z);
	view_get(&o->cam);
}

void			cam_init(t_cam *cam)
{
	cam->view.width = (double)WIDTH / 1000;
	cam->view.height = (double)HEIGHT / 1000;
	cam->view.dist = 1;
	vect_get_from_points(&cam->dir, cam->pos, cam->look);
	vect_normalise(&cam->dir, 0);
	vect_normalise(&cam->view.upvect, 1);
	vect_cros(&cam->view.rtvect, cam->view.upvect, cam->dir);
	vect_cros(&cam->view.upvect, cam->dir, cam->view.rtvect);
	view_get_upleft(&cam->view.upleft, cam);
	cam->xind = (cam->view.width / (double)WIDTH);
	cam->yind = (cam->view.height / (double)HEIGHT);
}
