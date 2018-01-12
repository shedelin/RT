/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 17:06:42 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:37:19 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

int			set_sphr(t_env *e, t_llex *lst, int min)
{
	int		val;
	t_obj	*obj;

	val = ft_atoi(lst->next->str);
	if (val <= min)
		return (error(ERR_VAL_VAL, OBJ_SPHERE, lst->str));
	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	((t_sphr *)(obj->obj))->rad = val;
	return (1);
}

int			aut_sphere(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] = {{_sphere, 0, SPH_SIZE, &is_value, NULL}};

	i = 0;
	while (i < SPH_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= SPH_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, OBJ_TYPE));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (!set_sphr(e, s_aut->l_lex, 0))
		return (0);
	return (1);
}

int			aut_sphere_init(t_env *e, t_saut *s_aut)
{
	t_sphr	*new;
	t_obj	*obj;

	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	CLOSE(0, &s_aut->l_lex, NULL);
	if (obj->obj)
		return (error(ERR_VAL_DONE, OBJ_TYPE, OBJ));
	if (!(new = (t_sphr *)malloc(sizeof(t_sphr))))
		return (error(ERR_MALLOC, "aut_sphere_init", s_aut->l_lex->str));
	obj->obj = (t_sphr *)new;
	obj->type = SPHERE;
	return (1);
}

int			scene_aut_sphere(t_env *e, t_saut *s_aut)
{
	char	*line;
	int		i;

	line = NULL;
	if (!aut_sphere_init(e, s_aut))
		return (CLOSE(0, &s_aut->l_lex, &line));
	i = -1;
	while (++i < SPH_VAL_NB && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (CLOSE(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_sphere(e, s_aut))
			return (CLOSE(0, &s_aut->l_lex, &line));
		CLOSE(0, &s_aut->l_lex, &line);
	}
	if (i < SPH_VAL_NB)
		return (CLOSE(error(ERR_VAL_FEW, OBJ, NULL), &s_aut->l_lex, &line));
	return (CLOSE(1, &s_aut->l_lex, &line));
}
