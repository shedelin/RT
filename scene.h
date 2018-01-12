/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 11:50:24 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:34:02 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structs.h"

/*
**	Scene must be defined by tokens and values.
**	CAM must be set before OBJ, if not default values will be set.
**	camrea can't be set after objetcs.
**	You can set tokens strings by changing defines in this header.
**	When integers are awaited, they must be lower than 10 ^ MAX_INT.
**	-> CAM
**	User can set 3 values on camera:
**	CAM_POS, CAM_LOOK, CAM_DIR that are each waiting 3 integers
**	if none, default values will be used.
**	-> SPOT
**	Two value are required: SPOT_POS and SPOT_COLOR with 3 integers.
**	If most or less pars error will occur.
**	-> OBJ
**	for values waited:
**	- OBJ_POS: 3 integers.
**	- OBJ_COLOR: 3 integers between 0 and 255
**	- OBJ_ROT_XYZ: 3 integers between 0 and 360
**	- OBJ_MATERIAL: Have to be set after OBJ_COLOR.
**	The next line expec a single token: MAT1, MAT2, MAT3.
**	- OBJ_TYPE: The next line expect the type:
**	- OBJ_SPHERE: the next line expect:
**	- SPH_SIZE:  one integer > 0.
**	- OBJ_PLANE: the next line expect:
**	- PLN_DIR: the normal vector. (3 integers)
**	- OBJ_CYLINDER: the next line expect:
**	- CYL_SIZE: one integer > 0.
**	- OBJ_CONE: the next line expect:
**	- CONE_ANGLE: one integer between 0 not included and 250
**	- OBJ_ELLIPS: the next line expect:
**	- ELLI_SIZES_XYZ: 3 integers > 0
*/

# define ERR_ARG			"one argument file needed"
# define ERR_FILE			"couldn't open file: "
# define ERR_CLOSE			"couldn't close file: "
# define ERR_MALLOC			"failed malloc in func: "
# define ERR_PARS_ARG		"pars, invalid token after: "
# define ERR_PARS_TOK		"pars, invalid token: "
# define ERR_TOK_POS		"pars, tokens must be set in order: "
# define ERR_TOK_DONE		"pars, invalid repeat token: "
# define ERR_VAL_NOT		"pars, unknown value for: "
# define ERR_VAL_DONE		"pars, invalid repeat value in "
# define ERR_VAL_FEW		"pars, not enought values set for "
# define ERR_VAL_VAL		"pars, value out of size in "
# define ERR_PARS_NB		"pars, too much values for token: "
# define ERR_VERT_FEW		"pars, too few arguments after: "
# define ERR_VERT_MANY		"pars, too many arguments after: "
# define ERR_VERT_INT		"pars, Arguments must be integer after: "
# define ERR_VAL_INT		"pars, single integer expected after: "

# define CLOSE				scene_aut_close

# define COMMENT_C			'#'
# define MAX_INT			6
# define PARS_TOK_NB		3

# define CAM				"camera"
# define CAM_VAL_NB			3
# define CAM_POS			"position"
# define CAM_LOOK			"look"
# define CAM_DIR			"direction"

# define SPOT				"spot"
# define SPOT_VAL_NB		2
# define SPOT_POS			"position"
# define SPOT_COLOR			"color"

# define OBJ				"object"
# define OBJ_VAL_NB			5
# define OBJ_POS			"position"
# define OBJ_ROT_XYZ		"rotation_xyz"
# define OBJ_COLOR			"color"
# define OBJ_TYPE			"type"
# define OBJ_MATERIAL		"material"

# define MAT_VAL_NB			10
# define MAT1				"mat1"
# define MAT2				"mat2"
# define MAT3				"mat3"
# define MAT4				"mat4"
# define MAT5				"mat5"
# define MAT6				"mat6"
# define MAT7				"mat7"
# define MAT8				"mat8"
# define MAT9				"mat9"
# define MAT10				"mat10"

# define TYPE_VAL_NB		5
# define OBJ_SPHERE			"sphere"
# define SPH_VAL_NB			1
# define SPH_SIZE			"size"

# define OBJ_PLANE			"plane"
# define PLN_VAL_NB			1
# define PLN_DIR			"direction"

# define OBJ_CYLINDER		"cylinder"
# define CYL_VAL_NB			1
# define CYL_SIZE			"size"

# define OBJ_CONE			"cone"
# define CONE_VAL_NB		1
# define CONE_ANGLE			"angle"

# define OBJ_ELLIPS			"ellipsoid"
# define ELLIPS_VAL_NB		1
# define ELLIPS_SIZES_XYZ	"sizes_xyz"

int			error(char *error, char *spec, char *in);

/*
**	lex_lst.c
*/
void		lex_lst_put(t_llex **l_lex);
void		lex_lst_del(t_llex **l_lex);
void		lex_lst_add(t_llex **l_lex, t_llex *new);
t_llex		*lex_lst_new(t_laut *aut);

/*
**	lex_automaton.c
*/
int			lex_aut_com(char c, t_laut *aut_l);
int			lex_aut_num(char c, t_laut *aut_l);
int			lex_aut_word(char c, t_laut *aut_l);
int			lex_aut_wait(char c, t_laut *aut_l);
int			lex_automaton(char c, t_laut *aut_l);

/*
**	lexer.c
*/
int			lex_add_token(t_laut *aut);
int			lex(char *line, t_llex **l_lex);

/*
**	scene_aut_cam.c (3 statics)
*/
void		cam_set_default(t_cam *cam);
int			scene_aut_cam(t_env *e, t_saut *s_aut);

/*
**	scene_aut_spot.c (1 static)
*/
t_spot		*spot_new(double x, double y, double z);
int			scene_aut_spot(t_env *e, t_saut *s_aut);

/*
**	scene_aut_obj.c (5 statics) ///
*/
int			scene_aut_obj(t_env *e, t_saut *s_aut);

/*
**	is.c
*/
int			is_vertex(t_llex *lst);
int			is_value(t_llex *lst);
int			is_token(t_llex *lst);
void		ft_get_scene_init(int *r, char **s, t_saut *a);

/*
**	scene_aut_otype.c
*/
int			aut_type(t_env *e, t_saut *s_aut);
int			scene_aut_type(t_env *e, t_saut *s_aut);

/*
**	scene_aut_mat.c
*/
void		mat_obj_set(t_env *e, int which);
int			aut_mat(t_env *e, t_saut *s_aut);
int			scene_aut_mat(t_env *e, t_saut *s_aut);

/*
**	aut_sphere.c
*/
int			set_sphr(t_env *e, t_llex *lst, int min);
int			aut_sphere_init(t_env *e, t_saut *s_aut);
int			scene_aut_sphere(t_env *e, t_saut *s_aut);
int			aut_sphere(t_env *e, t_saut *s_aut);

/*
**	aut_plane.c
*/
int			set_plane(t_env *e, t_llex *lst);
int			aut_plane(t_env *e, t_saut *s_aut);
int			aut_plane_init(t_env *e, t_saut *s_aut);
int			scene_aut_plane(t_env *e, t_saut *s_aut);

/*
**	aut_cylinder.c
*/
int			set_cylinder(t_env *e, t_llex *lst, int min);
int			aut_cylinder(t_env *e, t_saut *s_aut);
int			aut_cylinder_init(t_env *e, t_saut *s_aut);
int			scene_aut_cyl(t_env *e, t_saut *s_aut);

/*
**	aut_cone.c
*/
int			set_cone(t_env *e, t_llex *lst, int min, int max);
int			aut_cone(t_env *e, t_saut *s_aut);
int			aut_cone_init(t_env *e, t_saut *s_aut);
int			scene_aut_cone(t_env *e, t_saut *s_aut);

/*
**	aut_ellips.c
*/
int			set_ellips(t_env *e, t_llex *lst, int min);
int			aut_ellips(t_env *e, t_saut *s_aut);
int			aut_ellips_init(t_env *e, t_saut *s_aut);
int			scene_aut_ellips(t_env *e, t_saut *s_aut);

int			scene_aut_close(int ret, t_llex **lst, char **str);
int			scene_automaton(t_saut *s_aut, char *line, t_env *e);
int			scene_aut_start(t_env *e, t_saut *s_aut);
#endif
