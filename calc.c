/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:23:08 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 15:04:36 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

double		res_eq(double det, double a, double b)
{
	double	t1;
	double	t2;

	t1 = (double)0;
	if (det < t1)
		return (t1);
	else if (det == t1)
		return (-b / (2 * a));
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t1 < t2)
		return (t1);
	return (t2);
}

t_vect		add_vect(t_vect vec, t_vect *add)
{
	vec.x += add->x;
	vec.y += add->y;
	vec.z += add->z;
	return (vec);
}

t_vect		sub_vect(t_vect vec, t_vect *add)
{
	vec.x -= add->x;
	vec.y -= add->y;
	vec.z -= add->z;
	return (vec);
}

void		pos_get(t_pos *pos, double x, double y, double z)
{
	pos->x = x;
	pos->y = y;
	pos->z = z;
}
