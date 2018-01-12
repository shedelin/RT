/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:24:25 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:31:04 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

int			scene_aut_start(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] =

	{
	{_tcam, CAM_VAL_NB, CAM, &is_token, NULL},
	{_tspot, SPOT_VAL_NB, SPOT, &is_token, NULL},
	{_tobj, OBJ_VAL_NB, OBJ, &is_token, NULL}
	};
	i = 0;
	while (i < PARS_TOK_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= PARS_TOK_NB)
		return (error(ERR_PARS_TOK, s_aut->l_lex->str, NULL));
	s_aut->status = pars[i].status + 1;
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	return (scene_automaton(s_aut, NULL, e));
}

int			scene_aut_close(int ret, t_llex **lst, char **str)
{
	if (str)
		ft_strdel(str);
	lex_lst_del(lst);
	*lst = NULL;
	return (ret);
}

int			scene_automaton(t_saut *s_aut, char *line, t_env *e)
{
	static int	(*scene_aut_func[])(t_env *, t_saut *) =

	{
	&scene_aut_start,
	&scene_aut_cam,
	&scene_aut_spot,
	&scene_aut_obj
	};
	if (line && !lex(line, &s_aut->l_lex))
		return (CLOSE(0, &s_aut->l_lex, &line));
	if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
		return (CLOSE(1, &s_aut->l_lex, &line));
	ft_strdel(&line);
	if (!scene_aut_func[s_aut->status](e, s_aut))
		return (CLOSE(0, &s_aut->l_lex, &line));
	return (CLOSE(1, &s_aut->l_lex, &line));
}

static void	obj_cam_init(t_env *e)
{
	t_obj	*tmp;

	tmp = e->l_obj;
	while (tmp)
	{
		cam_obj_set(e, tmp);
		tmp = tmp->next;
	}
}

int			ft_get_scene(t_env *e, char *file)
{
	t_saut	s_aut;
	char	*line;
	int		restart;

	if ((s_aut.fd = open(file, O_RDONLY)) < 0)
		return (error(ERR_FILE, file, NULL));
	ft_get_scene_init(&restart, &line, &s_aut);
	while ((ft_get_next_line(s_aut.fd, &line, restart)) > 0)
	{
		restart = 0;
		if (!scene_automaton(&s_aut, line, e))
		{
			if (close(s_aut.fd) < 0)
				return (error(ERR_CLOSE, file, NULL));
			return (0);
		}
	}
	ft_strdel(&line);
	if (close(s_aut.fd) < 0)
		return (error(ERR_CLOSE, file, NULL));
	obj_cam_init(e);
	return (1);
}
