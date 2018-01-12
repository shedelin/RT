/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:48:02 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:37:04 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

int			set_plane(t_env *e, t_llex *lst)
{
	t_pos	tmp;
	t_obj	*obj;

	tmp.x = ft_atoi(lst->next->str);
	tmp.y = ft_atoi(lst->next->next->str);
	tmp.z = ft_atoi(lst->next->next->next->str);
	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	((t_pln *)(obj->obj))->dir = tmp;
	return (1);
}

int			aut_plane(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] = {{0, 0, PLN_DIR, &is_vertex, NULL}};

	i = 0;
	while (i < PLN_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= PLN_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, OBJ_TYPE));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (!set_plane(e, s_aut->l_lex))
		return (0);
	return (1);
}

int			aut_plane_init(t_env *e, t_saut *s_aut)
{
	t_pln	*new;
	t_obj	*obj;

	obj = e->l_obj;
	while (obj->next)
		obj = obj->next;
	CLOSE(0, &s_aut->l_lex, NULL);
	if (obj->obj)
		return (error(ERR_VAL_DONE, OBJ_TYPE, OBJ));
	if (!(new = (t_pln *)malloc(sizeof(t_pln))))
		return (error(ERR_MALLOC, "aut_plane_init", s_aut->l_lex->str));
	obj->obj = (t_pln *)new;
	obj->type = PLANE;
	return (1);
}

int			scene_aut_plane(t_env *e, t_saut *s_aut)
{
	char	*line;
	int		i;

	line = NULL;
	if (!aut_plane_init(e, s_aut))
		return (CLOSE(0, &s_aut->l_lex, &line));
	i = -1;
	while (++i < PLN_VAL_NB && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (CLOSE(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_plane(e, s_aut))
			return (CLOSE(0, &s_aut->l_lex, &line));
		CLOSE(0, &s_aut->l_lex, &line);
	}
	if (i < PLN_VAL_NB)
		return (CLOSE(error(ERR_VAL_FEW, OBJ, NULL), &s_aut->l_lex, &line));
	return (CLOSE(1, &s_aut->l_lex, &line));
}
