/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_automaton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:41:05 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 15:27:59 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

int			lex_aut_com(char c, t_laut *aut_l)
{
	if (!c)
	{
		if (!lex_add_token(aut_l))
			return (0);
		aut_l->status = _lwait;
		return (lex_aut_wait(c, aut_l));
	}
	aut_l->buf[aut_l->i] = c;
	aut_l->i += 1;
	return (1);
}

int			lex_aut_num(char c, t_laut *aut_l)
{
	if (!c || c == ' ' || c == '\t' || c == COMMENT_C)
	{
		if (!lex_add_token(aut_l))
			return (0);
		aut_l->status = _lwait;
		return (lex_aut_wait(c, aut_l));
	}
	if (!(ft_isdigit(c) || (aut_l->i == 0 && c == '-')))
		aut_l->status = _word;
	aut_l->buf[aut_l->i] = c;
	aut_l->i += 1;
	return (1);
}

int			lex_aut_word(char c, t_laut *aut_l)
{
	if (!c || c == ' ' || c == '\t' || c == COMMENT_C)
	{
		if (!lex_add_token(aut_l))
			return (0);
		aut_l->status = _lwait;
		return (lex_aut_wait(c, aut_l));
	}
	aut_l->buf[aut_l->i] = c;
	aut_l->i += 1;
	return (1);
}

int			lex_aut_wait(char c, t_laut *aut_l)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c == COMMENT_C)
		aut_l->status = _comment;
	else if (ft_isdigit(c) || (aut_l->i == 0 && c == '-'))
		aut_l->status = _num;
	else
		aut_l->status = _word;
	aut_l->buf[aut_l->i] = c;
	aut_l->i += 1;
	return (1);
}

int			lex_automaton(char c, t_laut *aut_l)
{
	static int	(*lex_aut_func[])(char, t_laut *) =

	{
	&lex_aut_wait,
	&lex_aut_word,
	&lex_aut_num,
	&lex_aut_com
	};
	if (!lex_aut_func[aut_l->status](c, aut_l))
		return (0);
	return (1);
}
