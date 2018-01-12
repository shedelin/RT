/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:29:33 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/26 19:00:30 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				color_pixel_get(t_env *e, t_obj *o, int depth)
{
	t_ccolor	ccol;
	t_color		lcolor;

	ccol = light_get(e, o, depth);
	if (ccol.r > 1)
		ccol.r = 1;
	if (ccol.g > 1)
		ccol.g = 1;
	if (ccol.b > 1)
		ccol.b = 1;
	lcolor.r = (int)(255 * ccol.r);
	lcolor.g = (int)(255 * ccol.g);
	lcolor.b = (int)(255 * ccol.b);
	return (COL(lcolor.r, lcolor.g, lcolor.b));
}

t_ccolor		add_ccolor(t_ccolor col1, t_ccolor col2)
{
	col1.r += col2.r;
	col1.g += col2.g;
	col1.b += col2.b;
	return (col1);
}

t_ccolor		ccolor_get_double(double r, double g, double b)
{
	t_ccolor	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

void			ccolor_normalise(t_ccolor *ccol)
{
	if (ccol->r > 1)
		ccol->r = 1;
	if (ccol->g > 1)
		ccol->g = 1;
	if (ccol->b > 1)
		ccol->b = 1;
}

t_ccolor		ccolor_get(int r, int g, int b)
{
	t_ccolor	col;

	col.r = (double)r / 255;
	col.g = (double)g / 255;
	col.b = (double)b / 255;
	return (col);
}
