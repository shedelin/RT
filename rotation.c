/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:19:55 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/26 17:07:03 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "rtv1.h"

/*
**	rot_init_x_matrix:
**	Initiates a vertical matrix of the form
**		  (  1    0    0  )
**	M(ß)= (  0  cosß -sinß)
**		  (  0  sinß  cosß)
*/

/*
**	rot_init_y_matrix:
**	Initiates a horizontal matrix of the form
**		  ( cosß  0   sinß)
**	M(ß)= (  0    1    0  )
**		  (-sinß  0   cosß)
*/

void			rot_apply(t_vect *rot, double **mat)
{
	t_vect		vec;

	vec = *rot;
	rot->x = vec.x * mat[0][0] + vec.y * mat[1][0] + vec.z * mat[2][0];
	rot->y = vec.x * mat[0][1] + vec.y * mat[1][1] + vec.z * mat[2][1];
	rot->z = vec.x * mat[0][2] + vec.y * mat[1][2] + vec.z * mat[2][2];
}

static double	**rot_init_matrix(void)
{
	double	**matrix;
	int		i;

	i = 0;
	matrix = (double **)malloc(3 * sizeof(double *));
	while (i < 3)
	{
		matrix[i] = (double *)malloc(3 * sizeof(double));
		i++;
	}
	return (matrix);
}

double			**rot_init_x_matrix(double angle)
{
	double		**matrix;

	matrix = rot_init_matrix();
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(angle);
	matrix[1][2] = -sin(angle);
	matrix[2][0] = 0;
	matrix[2][1] = sin(angle);
	matrix[2][2] = cos(angle);
	return (matrix);
}

double			**rot_init_y_matrix(double angle)
{
	double			**matrix;

	matrix = rot_init_matrix();
	matrix[0][0] = cos(angle);
	matrix[0][1] = 0;
	matrix[0][2] = sin(angle);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(angle);
	matrix[2][1] = 0;
	matrix[2][2] = cos(angle);
	return (matrix);
}

double			**rot_init_z_matrix(double angle)
{
	double		**matrix;

	matrix = rot_init_matrix();
	matrix[0][0] = cos(angle);
	matrix[0][1] = -sin(angle);
	matrix[0][2] = 0;
	matrix[1][0] = sin(angle);
	matrix[1][1] = cos(angle);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	return (matrix);
}
