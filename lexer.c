/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:44:21 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/18 18:35:07 by caupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

int			lex_add_token(t_laut *aut)
{
	t_llex	*new;

	if (!(new = lex_lst_new(aut)))
	{
		aut->l_lex = NULL;
		return (0);
	}
	lex_lst_add(&aut->l_lex, new);
	aut->i = 0;
	ft_bzero(aut->buf, ft_strlen(aut->buf));
	return (1);
}

int			lex(char *line, t_llex **l_lex)
{
	t_laut	aut_l;
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(line);
	if (!(aut_l.buf = ft_strnew(size)))
		return (error(ERR_MALLOC, "lex()", NULL));
	aut_l.status = _lwait;
	aut_l.i = 0;
	aut_l.l_lex = NULL;
	while (++i <= size)
	{
		if (!lex_automaton(line[i], &aut_l))
			return (0);
	}
	*l_lex = aut_l.l_lex;
	ft_strdel(&aut_l.buf);
	return (1);
}
