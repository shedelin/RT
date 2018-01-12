/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_aut_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:47:02 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 18:08:25 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"
#include "scene.h"

void			cam_set_default(t_cam *cam)
{
	pos_get(&cam->pos, 20, 20, 20);
	pos_get(&cam->look, 0, 0, 0);
	vect_get(&cam->view.upvect, 0, 1, 0);
}

static int		aut_cam_init(t_env *e, t_saut *s_aut)
{
	if (s_aut->done[_tcam])
		return (error(ERR_TOK_DONE, CAM, NULL));
	if (s_aut->done[_tobj])
		return (error(ERR_TOK_POS, CAM, OBJ));
	cam_set_default(&e->cam);
	return (1);
}

static int		scene_aut_cam_set(t_env *e, int wich, t_llex *lst, int *done)
{
	t_pos		tmp;

	tmp.x = (double)ft_atoi(lst->next->str);
	tmp.y = (double)ft_atoi(lst->next->next->str);
	tmp.z = (double)ft_atoi(lst->next->next->next->str);
	if (done[wich])
		return (error(ERR_VAL_DONE, lst->str, CAM));
	if (wich == _cpos)
		e->cam.pos = tmp;
	if (wich == _clook)
		e->cam.look = tmp;
	if (wich == _cdir)
		e->cam.view.upvect = tmp;
	done[wich] = 1;
	return (1);
}

static int		aut_cam(t_env *e, t_saut *s_aut, int *done)
{
	int				i;
	static t_pars	pars[] =

	{
	{_cpos, 0, CAM_POS, &is_vertex, NULL},
	{_clook, 0, CAM_LOOK, &is_vertex, NULL},
	{_cdir, 0, CAM_DIR, &is_vertex, NULL},
	};
	i = 0;
	while (i < CAM_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= CAM_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, CAM));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (!scene_aut_cam_set(e, i, s_aut->l_lex, done))
		return (0);
	return (1);
}

int				scene_aut_cam(t_env *e, t_saut *s_aut)
{
	int			done[CAM_VAL_NB];
	int			i;
	char		*line;

	ft_bzero(done, CAM_VAL_NB * sizeof(int));
	CLOSE(0, &s_aut->l_lex, NULL);
	if (!aut_cam_init(e, s_aut))
		return (0);
	line = NULL;
	i = -1;
	while (++i < CAM_VAL_NB && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (CLOSE(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_cam(e, s_aut, done))
			return (CLOSE(0, &s_aut->l_lex, &line));
		CLOSE(0, &s_aut->l_lex, &line);
	}
	s_aut->status = _start;
	s_aut->done[_tcam] = 1;
	return (CLOSE(1, &s_aut->l_lex, &line));
}
