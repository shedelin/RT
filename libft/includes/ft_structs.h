/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:31:57 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/26 18:33:02 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}					t_list;

#endif
