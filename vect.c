/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:37:56 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 17:27:07 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

/*
** Calculates reflected vector with
** r = 2(n•i)n-i
** with n the normal vector and i the icident vector
*/
t_vect		vect_get_reflected(t_vect n, t_vect i)
{
	t_vect		reflect;
	double		dotin;

	dotin = -DOT(i, n);
	reflect.x = 2 * dotin * n.x - -i.x;
	reflect.y = 2 * dotin * n.y - -i.y;
	reflect.z = 2 * dotin * n.z - -i.z;
	vect_normalise(&reflect, 0);
	return (reflect);
}

void		vect_get(t_vect *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

void		vect_get_from_points(t_vect *vect, t_pos a, t_pos b)
{
	vect_get(vect, b.x - a.x, b.y - a.y, b.z - a.z);
}

void		vect_normalise(t_vect *vect, double length)
{
	if (!length)
		length = sqrt(SQUARE(vect->x) + SQUARE(vect->y) + SQUARE(vect->z));
	vect_get(vect, vect->x / length, vect->y / length, vect->z / length);
}

void		vect_cros(t_vect *vect, t_vect a, t_vect b)
{
	vect->x = MULT(a.y, b.z) - MULT(a.z, b.y);
	vect->y = MULT(a.z, b.x) - MULT(a.x, b.z);
	vect->z = MULT(a.x, b.y) - MULT(a.y, b.x);
}
