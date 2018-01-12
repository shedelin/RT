/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_aut_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:29:22 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:34:47 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

void		mat_obj_set(t_env *e, int which)
{
	t_obj	*tmp;

	tmp = e->l_obj;
	while (tmp->next)
		tmp = tmp->next;
	material_init(tmp, materials(which));
}

int			aut_mat(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] =

	{
	{0, 0, MAT1, &is_token, NULL},
	{1, 0, MAT2, &is_token, NULL},
	{2, 0, MAT3, &is_token, NULL},
	{3, 0, MAT4, &is_token, NULL},
	{4, 0, MAT5, &is_token, NULL},
	{5, 0, MAT6, &is_token, NULL},
	{6, 0, MAT7, &is_token, NULL},
	{7, 0, MAT8, &is_token, NULL},
	{8, 0, MAT9, &is_token, NULL},
	{9, 0, MAT10, &is_token, NULL}
	};
	i = 0;
	while (i < MAT_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= MAT_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, OBJ_MATERIAL));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	mat_obj_set(e, i);
	return (1);
}

int			scene_aut_mat(t_env *e, t_saut *s_aut)
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
		else if (!aut_mat(e, s_aut))
			return (scene_aut_close(0, &s_aut->l_lex, &line));
		scene_aut_close(0, &s_aut->l_lex, &line);
	}
	if (i < 1)
		return (CLOSE(error(ERR_VAL_FEW, OBJ, NULL), &s_aut->l_lex, &line));
	return (CLOSE(1, &s_aut->l_lex, &line));
}
