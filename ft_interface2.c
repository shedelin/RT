/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interface2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin <cmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:54:46 by cmartin           #+#    #+#             */
/*   Updated: 2014/03/27 18:33:13 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <mlx.h>

int	ft_fill_img1(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while ((++x + 1) < WIDTH)
	{
		mlx_pixel_put(e->mlx, e->win, x + 50, y + 30, 0xFF0000);
	}
	while ((++y + 1) < HEIGHT)
	{
		mlx_pixel_put(e->mlx, e->win, x + 50, y + 30, 0xFF0000);
	}
	while (--x > 0)
	{
		mlx_pixel_put(e->mlx, e->win, x + 50, y + 30, 0xFF0000);
	}
	while (--y > 0)
	{
		mlx_pixel_put(e->mlx, e->win, x + 50, y + 30, 0xFF0000);
	}
	return (-1);
}
