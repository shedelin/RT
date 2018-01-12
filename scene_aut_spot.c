/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_aut_spot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 20:27:39 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:15 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

static int		aut_spot_set(t_env *e, int wich, t_llex *lst)
{
	t_pos		val;
	t_spot		*tmp;

	val.x = (double)ft_atoi(lst->next->str);
	val.y = (double)ft_atoi(lst->next->next->str);
	val.z = (double)ft_atoi(lst->next->next->next->str);
	tmp = e->l_spot;
	while (tmp->next)
		tmp = tmp->next;
	if (wich == 0)
		tmp->ray.or = val;
	if (wich == 1)
	{
		if (val.x < 0 || val.x > 255 || val.y < 0 || val.y > 255
			|| val.z < 0 || val.z > 255)
			return (error(ERR_VAL_VAL, SPOT, SPOT_COLOR));
		tmp->ccol.r = val.x / 255;
		tmp->ccol.g = val.y / 255;
		tmp->ccol.b = val.z / 255;
	}
	return (1);
}

static int		aut_spot(t_env *e, t_saut *s_aut)
{
	int				i;
	static t_pars	pars[] =

	{
	{0, 0, SPOT_POS, &is_vertex, NULL},
	{1, 0, SPOT_COLOR, &is_vertex, NULL}
	};
	i = 0;
	while (i < SPOT_VAL_NB && !ft_strequ(s_aut->l_lex->str, pars[i].str))
		i++;
	if (i >= SPOT_VAL_NB)
		return (error(ERR_VAL_NOT, s_aut->l_lex->str, SPOT));
	if (!pars[i].is(s_aut->l_lex))
		return (0);
	if (!aut_spot_set(e, i, s_aut->l_lex))
		return (0);
	return (1);
}

static int		aut_spot_init(t_env *e, t_saut *s_aut)
{
	t_spot	*new;
	t_spot	*tmp;

	CLOSE(0, &s_aut->l_lex, NULL);
	if (!(new = (t_spot *)malloc(sizeof(t_spot))))
		return (error(ERR_MALLOC, "scene_aut_spot_add", NULL));
	new->next = NULL;
	if (!e->l_spot)
		e->l_spot = new;
	else
	{
		tmp = e->l_spot;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int				scene_aut_spot(t_env *e, t_saut *s_aut)
{
	char	*line;
	int		i;

	line = NULL;
	i = -1;
	if (!aut_spot_init(e, s_aut))
		return (0);
	while (++i < SPOT_VAL_NB && ft_get_next_line(s_aut->fd, &line, 0) > 0)
	{
		if (!lex(line, &s_aut->l_lex))
			return (CLOSE(0, &s_aut->l_lex, &line));
		if (!s_aut->l_lex || s_aut->l_lex->type == _comment)
			i--;
		else if (!aut_spot(e, s_aut))
			return (CLOSE(0, &s_aut->l_lex, &line));
		CLOSE(0, &s_aut->l_lex, &line);
	}
	if (i < SPOT_VAL_NB)
		return (CLOSE(error(ERR_VAL_FEW, SPOT, NULL), &s_aut->l_lex, &line));
	s_aut->status = _start;
	s_aut->done[_tspot] += 1;
	return (CLOSE(1, &s_aut->l_lex, &line));
}
