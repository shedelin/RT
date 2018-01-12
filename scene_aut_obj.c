/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_aut_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 12:40:39 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:56 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

static int	obj_get_rot(t_obj *obj, t_pos rot, int min, int max)
{
	int		ret;

	ret = 0;
	if (rot.x < min || rot.x > max || rot.y < min || rot.y > max)
		return (error(ERR_VAL_VAL, OBJ, OBJ_ROT_XYZ));
	if (rot.z < min || rot.z > max)
		return (error(ERR_VAL_VAL, OBJ, OBJ_ROT_XYZ));
	ret += !(obj->rot.x = rot_init_x_matrix(TORAD(rot.x)));
	ret += !(obj->rot.y = rot_init_y_matrix(TORAD(rot.y)));
	ret += !(obj->rot.z = rot_init_z_matrix(TORAD(rot.z)));
	ret += !(obj->invrot.x = rot_init_x_matrix(TORAD(-rot.x)));
	ret += !(obj->invrot.y = rot_init_y_matrix(TORAD(-rot.y)));
	ret += !(obj->invrot.z = rot_init_z_matrix(TORAD(-rot.z)));
	if (ret)
		return (error(ERR_MALLOC, "obj_get_rot()", NULL));
	return (1);
}

static int	scene_aut_obj_set(t_env *e, int wich, t_llex *lst)
{
	t_obj	*obj;
	t_pos	tmp;

	obj = e->l_obj;
	tmp.x = (double)ft_atoi(lst->next->str);
	tmp.y = (double)ft_atoi(lst->next->next->str);
	tmp.z = (double)ft_atoi(lst->next->next->next->str);
	while (obj->next)
		obj = obj->next;
	if (wich == _opos)
		obj->or = tmp;
	if (wich == _orot && !obj_get_rot(obj, tmp, 0, 360))
		return (0);
	if (wich == _ocolor && !obj_set_color(obj, tmp, 0, 255))
		return (0);
	return (1);
}

static int	aut_obj_init(t_env *e, t_saut *s_aut)
{
	t_obj	*new;

	if (!s_aut->done[_tcam])
		cam_set_default(&e->cam);
	if (!s_aut->done[_tobj])
		cam_init(&e->cam);
	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		return (error(ERR_MALLOC, "aut_obj_init", s_aut->l_lex->str));
	new->next = NULL;
	new->obj = NULL;
	new->rot.y = NULL;
	new->rot.x = NULL;
	new->rot.z = NULL;
	new->invrot.x = NULL;
	new->invrot.y = NULL;
	new->invrot.z = NULL;
	ft_obj_add(&e->l_obj, new);
	CLOSE(0, &s_aut->l_lex, NULL);
	return (1);
}

static int	aut_obj(t_env *e, t_saut *s_aut, int done[OBJ_VAL_NB])
{
	int				i;
	static t_pars	pars[] =

	{
	{_opos, 0, OBJ_POS, &is_vertex, NULL},
	{_orot, 0, OBJ_ROT_XYZ, &is_vertex, NULL},
	{_ocolor, 0, OBJ_COLOR, &is_vertex, NULL},
	{_otype, 0, OBJ_TYPE, &is_token, &scene_aut_type},
	{_omat, 0, OBJ_MATERIAL, &is_token, &scene_aut_mat}
	};
	i = 0;
	while (i < OBJ_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= OBJ_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, OBJ));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (done[i] || (i == _omat && !done[_ocolor]))
		return (error(ERR_VAL_DONE, s_aut->l_lex->str, OBJ));
	if ((i == _otype || i == _omat) && !pars[i].use(e, s_aut))
		return (0);
	else if (i != 3 && i != 4 && !scene_aut_obj_set(e, i, s_aut->l_lex))
		return (0);
	done[i] = 1;
	return (1);
}

int			scene_aut_obj(t_env *e, t_saut *s_aut)
{
	int		done[OBJ_VAL_NB];
	char	*line;
	int		i;

	ft_bzero(done, OBJ_VAL_NB * sizeof(int));
	line = NULL;
	i = -1;
	if (!aut_obj_init(e, s_aut))
		return (CLOSE(0, &s_aut->l_lex, NULL));
	while (++i < OBJ_VAL_NB && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (CLOSE(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_obj(e, s_aut, done))
			return (CLOSE(0, &s_aut->l_lex, &line));
		CLOSE(0, &s_aut->l_lex, &line);
	}
	if (i < OBJ_VAL_NB)
		return (CLOSE(error(ERR_VAL_FEW, OBJ, NULL), &s_aut->l_lex, &line));
	s_aut->status = _start;
	s_aut->done[_tobj] += 1;
	return (CLOSE(1, &s_aut->l_lex, &line));
}
