/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:21:58 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/27 18:04:45 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define	RTV1_H

# include	"structs.h"

# define	WIDTH			1024
# define	HEIGHT			768

# define	SPHERE			0
# define	PLANE			1
# define	CYLINDER		2
# define	CONE			3
# define	ELLIPSOID		4

# define	DEPTH			2
# define	MAXT			10000000.0
# define	PI				3.14159265359
# define	TORAD(a)		((a) / 180.0 * PI)
# define	TODEG(a)		((a) * (180.0 / PI))
# define	SQUARE(v)		((v * v))
# define	MULT(u, v)		((v * u))
# define	COL(r, g, b)	((b) | ((g) << 8) | ((r) << 16))
# define	GETB(c)			((c) & 0x000000FF)
# define	GETR(c)			((c) >> 16)
# define	GETG(c)			((c) >> 8 & 0x000000FF)
# define	DOT(va, vb)		((va.x * vb.x + va.y * vb.y + va.z * vb.z))
# define	MAG(va)			((sqrt(va.x * va.x + va.y * va.y + va.z * va.z)))
# define	PERCOL(col)		((double)(col) / 255)

/*
**	mlx.c
*/
void		ft_mlx_init(t_env *e, t_vimg *img);
int			ft_loop(t_env *e);
int			key_hook(int key, t_env *e);
int			mouse_hook(int button, int x, int y, t_env *e);

/*
**	obj.c
*/
int			obj_set_color(t_obj *obj, t_pos pos, int min, int max);
void		ft_obj_del(t_obj **obj);
void		ft_obj_add(t_obj **l_obj, t_obj *new);

/*
**	scene.c (1 static)
*/
int			ft_get_scene(t_env *e, char *file);

/*
**	draw.c (1 static)
*/
double		get_hit(t_ray *r, t_obj *tmp);
void		ft_draw_pix(int x, int y, t_env *e);
void		obj_get_hit(t_obj *o);

/*
**	color.c
*/
int			color_pixel_get(t_env *e, t_obj *o, int depth);
t_ccolor	ccolor_get(int r, int g, int b);
t_ccolor	add_ccolor(t_ccolor col1, t_ccolor col2);
t_ccolor	ccolor_get_double(double r, double g, double b);
void		ccolor_normalise(t_ccolor *ccol);

/*
**	light.c (1 static)
*/
t_ccolor	light_get(t_env *e, t_obj *chit, int i);
t_ray		light_get_dir(t_ray spot, t_obj *obj, t_pos *hit);

/*
**	diffuse.c (2 statics)
*/
t_ccolor	light_get_diffuse(t_spot *spot, t_obj *obj, double coef2);

/*
**	specular.c
*/
t_ccolor	light_get_specular(t_spot *spot, t_obj *obj);

/*
**	reflection.c
*/
t_ccolor	light_get_reflection(t_env *e, t_obj *obj, int i);
t_ccolor	fresnel(t_ccolor col1, t_ccolor col2, t_obj *obj);

/*
**	cam.c (1 static)
*/
void		cam_init(t_cam *cam);
void		cam_obj_set(t_env *e, t_obj *o);
void		view_get(t_cam *cam);

/*
**	ray.c (1 static)
*/
void		ray_init(t_ray *r, t_cam *cam, int x, int y);

/*
**	sphere.c
*/
double		sphr_get_hit(t_ray *r, void *sphr);
double		sphr_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam);

/*
**	plane.c
*/
double		pln_get_hit(t_ray *r, void *pln);
double		pln_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam);

/*
**	cylinder.c
*/
double		cyl_get_hit(t_ray *r, void *cyl);
double		cyl_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam);

/*
**	cone.c
*/
double		cone_get_hit(t_ray *r, void *cone);
double		cone_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam);

/*
**	ellipsoid.c
*/
double		ellips_get_hit(t_ray *r, void *ellips);
double		ellips_get_light_angle(t_ray *spot, t_obj *obj, t_ray *rcam);

/*
**	calc.c
*/
double		square(double x);
double		mult(double x, double y);
double		res_eq(double det, double a, double b);
void		pos_get(t_pos *pos, double x, double y, double z);
t_vect		add_vect(t_vect vec, t_vect *add);
t_vect		sub_vect(t_vect vec, t_vect *add);

/*
**	vect.c
*/
void		vect_get(t_vect *vect, double x, double y, double z);
void		vect_get_from_points(t_vect *vect, t_pos a, t_pos b);
void		vect_normalise(t_vect *vect, double length);
void		vect_cros(t_vect *vect, t_vect a, t_vect b);
t_vect		vect_get_reflected(t_vect n, t_vect i);

/*
**	rotation.c (1 static)
*/
void		rot_apply(t_vect *v, double **mat);
double		**rot_init_x_matrix(double angle);
double		**rot_init_y_matrix(double angle);
double		**rot_init_z_matrix(double angle);

/*
**	materials.c
*/
t_mater		materials(int i);
void		material_init(t_obj *o, t_mater mat);

/*
**	ft_interface.c
*/
void		put_button(int selected_button, int x, t_env *env);
int			put_img(t_env *env);
int			which_position(int x, int y, int tmp, t_env *env);
void		ft_init_button(t_env *env);
int			ft_get_selected_scene(t_env *env);

/*
**	ft_interface2.c
*/
int			ft_fill_img1(t_env *env);

/*
**	ft_del_env.c
*/
void		ft_del(t_env *e);
void		ft_spot_del(t_spot **spot);
void		reset_draw(t_env *e, int selected);

#endif
