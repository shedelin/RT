/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:47:47 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:36:22 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

int			set_cone(t_env *e, t_llex *lst, int min, int max)
{
	int		val;
	double	tmp;
	t_obj	*obj;

	val = ft_atoi(lst->next->str);
	if (val <= min || val > max)
		return (error(ERR_VAL_VAL, OBJ_CONE, lst->str));
	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	tmp = (double)val;
	((t_cone *)(obj->obj))->tan_a = tmp / 1000;
	return (1);
}

int			aut_cone(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] = {{0, 0, CONE_ANGLE, &is_value, NULL}};

	i = 0;
	while (i < CONE_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= CONE_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, OBJ_TYPE));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (!set_cone(e, s_aut->l_lex, 0, 250))
		return (0);
	return (1);
}

int			aut_cone_init(t_env *e, t_saut *s_aut)
{
	t_cone	*new;
	t_obj	*obj;

	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	CLOSE(0, &s_aut->l_lex, NULL);
	if (obj->obj)
		return (error(ERR_VAL_DONE, OBJ_TYPE, OBJ));
	if (!(new = (t_cone *)malloc(sizeof(t_cyl))))
		return (error(ERR_MALLOC, "aut_cone_init", s_aut->l_lex->str));
	obj->obj = (t_cone *)new;
	obj->type = CONE;
	return (1);
}

int			scene_aut_cone(t_env *e, t_saut *s_aut)
{
	char	*line;
	int		i;

	line = NULL;
	if (!aut_cone_init(e, s_aut))
		return (CLOSE(0, &s_aut->l_lex, &line));
	i = -1;
	while (++i < CONE_VAL_NB && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (CLOSE(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_cone(e, s_aut))
			return (CLOSE(0, &s_aut->l_lex, &line));
		CLOSE(0, &s_aut->l_lex, &line);
	}
	if (i < CONE_VAL_NB)
		return (CLOSE(error(ERR_VAL_FEW, OBJ, NULL), &s_aut->l_lex, &line));
	return (CLOSE(1, &s_aut->l_lex, &line));
}
