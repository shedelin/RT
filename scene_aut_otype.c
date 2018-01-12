/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_aut_otype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:53:50 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:39 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"
#include "libft.h"

int			aut_type(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] =

	{
	{_sphere, 0, OBJ_SPHERE, &is_token, &scene_aut_sphere},
	{_plan, 0, OBJ_PLANE, &is_token, &scene_aut_plane},
	{_cyl, 0, OBJ_CYLINDER, &is_token, &scene_aut_cyl},
	{_cone, 0, OBJ_CONE, &is_token, &scene_aut_cone},
	{_elli, 0, OBJ_ELLIPS, &is_token, &scene_aut_ellips}
	};
	i = 0;
	while (i < TYPE_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= TYPE_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, OBJ_TYPE));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (!pars[i].use(e, s_aut))
		return (0);
	return (1);
}

int			scene_aut_type(t_env *e, t_saut *s_aut)
{
	char	*line;
	int		i;

	line = NULL;
	scene_aut_close(0, &s_aut->l_lex, NULL);
	i = -1;
	while (++i < 1 && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (scene_aut_close(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_type(e, s_aut))
			return (scene_aut_close(0, &s_aut->l_lex, &line));
		scene_aut_close(0, &s_aut->l_lex, &line);
	}
	if (i < 1)
		return (CLOSE(error(ERR_VAL_FEW, OBJ, NULL), &s_aut->l_lex, &line));
	return (scene_aut_close(1, &s_aut->l_lex, &line));
}
