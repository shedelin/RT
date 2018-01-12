/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:25:20 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/27 21:20:29 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"

/*
**	A material is define as :
**	Name, Diff coefs, Spec coefs, Spec pow, Refl, Blur
**	Name = The name of the material
**	Diff coefs = Coefficients for R, G and B to compute diffuse light
**	Spec coefs = Coefficients for R, G and B to compute specular light
**	Spec pow = Exponent to compute specular light
**	Reflect = Coefficient of reflectance
**	Blur = The size of the area of reflection (makes blurred reflections)
*/

void			material_init(t_obj *obj, t_mater mat)
{
	obj->mat.diff.r = mat.diff.r * ((double)obj->color.r / 255);
	obj->mat.diff.g = mat.diff.g * ((double)obj->color.g / 255);
	obj->mat.diff.b = mat.diff.b * ((double)obj->color.b / 255);
	obj->mat.spec = mat.spec;
	obj->mat.shin = mat.shin;
	obj->mat.refl = mat.refl;
	obj->mat.sblur = mat.sblur;
}

t_mater			materials(int i)
{
	static t_mater	mat[] =

	{
	{"mat1", {1, 1, 1}, 1, 100, 0.3, 0.002},
	{"mat2", {1, 1, 1}, 1, 70, 1, 0.01},
	{"mat3", {1, 1, 1}, 1, 200, 0, 0.001},
	{"mat4", {1, 1, 1}, 1, 50, 0.3, 0.01},
	{"mat5", {1, 1, 1}, 1, 40, 0.6, 0.2},
	{"mat6", {1, 1, 1}, 0.3, 5, 1, 0.1},
	{"mat7", {1, 1, 1}, 0.8, 200, 0.5, 0.1},
	{"mat8", {1, 1, 1}, 0.5, 30, 0.7, 5},
	{"mat9", {1, 1, 1}, 0.4, 20, 0.8, 1},
	{"mat10", {1, 1, 1}, 0.4, 10, 0.9, 0.1},
	};
	return (mat[i]);
}
