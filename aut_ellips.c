/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_ellips.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 19:02:57 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:37:35 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

int			set_ellips(t_env *e, t_llex *lst, int min)
{
	t_pos	tmp;
	t_obj	*obj;

	tmp.x = (double)ft_atoi(lst->next->str);
	tmp.y = (double)ft_atoi(lst->next->next->str);
	tmp.z = (double)ft_atoi(lst->next->next->next->str);
	if (tmp.x <= min || tmp.y <= min || tmp.z <= min)
		return (error(ERR_VAL_VAL, OBJ_ELLIPS, lst->str));
	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	((t_ellips *)(obj->obj))->size = tmp;
	tmp = ((t_ellips *)(obj->obj))->size;
	return (1);
}

int			aut_ellips(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] = {{0, 0, ELLIPS_SIZES_XYZ, &is_vertex, NULL}};

	i = 0;
	while (i < ELLIPS_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= ELLIPS_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, OBJ_TYPE));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (!set_ellips(e, s_aut->l_lex, 0))
		return (0);
	return (1);
}

int			aut_ellips_init(t_env *e, t_saut *s_aut)
{
	t_ellips	*new;
	t_obj		*obj;

	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	CLOSE(0, &s_aut->l_lex, NULL);
	if (obj->obj)
		return (error(ERR_VAL_DONE, OBJ_TYPE, OBJ));
	if (!(new = (t_ellips *)malloc(sizeof(t_ellips))))
		return (error(ERR_MALLOC, "aut_ellips_init", s_aut->l_lex->str));
	obj->obj = (t_ellips *)new;
	obj->type = ELLIPSOID;
	return (1);
}

int			scene_aut_ellips(t_env *e, t_saut *s_aut)
{
	char	*line;
	int		i;

	line = NULL;
	if (!aut_ellips_init(e, s_aut))
		return (CLOSE(0, &s_aut->l_lex, &line));
	i = -1;
	while (++i < ELLIPS_VAL_NB && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (CLOSE(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_ellips(e, s_aut))
			return (CLOSE(0, &s_aut->l_lex, &line));
		CLOSE(0, &s_aut->l_lex, &line);
	}
	if (i < ELLIPS_VAL_NB)
		return (CLOSE(error(ERR_VAL_FEW, OBJ, NULL), &s_aut->l_lex, &line));
	return (CLOSE(1, &s_aut->l_lex, &line));
}
