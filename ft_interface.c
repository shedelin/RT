/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin <cmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:28:59 by cmartin           #+#    #+#             */
/*   Updated: 2014/03/27 18:06:03 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "rtv1.h"

int		ft_get_selected_scene(t_env *e)
{
	static char	*tab[6] =

	{"map.sc", "map2.sc", "map3.sc", "map4.sc", "map5.sc", "map6.sc"};
	if (e->selected_button >= 0 && e->status)
	{
		e->status = 0;
		if (!ft_get_scene(e, tab[e->selected_button]))
		{
			e->fail = 1;
			mlx_put_image_to_window(e->mlx, e->win, e->black, 50, 30);
			mlx_put_image_to_window(e->mlx, e->win, e->owl, 260, 160);
			ft_fill_img1(e);
			e->draw = 0;
			e->status = 1;
			ft_del(e);
			return (-1);
		}
		e->fail = 0;
	}
	return (0);
}

int		which_position(int x, int y, int tmp, t_env *env)
{
	if ((x >= 150 && x <= 200) && (y >= 895 && y <= 950))
		tmp = 0;
	else if ((x >= 290 && x <= 340) && (y >= 895 && y <= 950))
		tmp = 1;
	else if ((x >= 430 && x <= 480) && (y >= 895 && y <= 950))
		tmp = 2;
	else if ((x >= 570 && x <= 620) && (y >= 895 && y <= 950))
		tmp = 3;
	else if ((x >= 710 && x <= 760) && (y >= 895 && y <= 950))
		tmp = 4;
	else if ((x >= 850 && x <= 900) && (y >= 895 && y <= 950))
		tmp = 5;
	else if ((x >= 977 && x <= 1057) && (y >= 1130 && y <= 1210))
	{
		mlx_destroy_image(env->mlx, env->img.ptr);
		ft_del(env);
		exit (0);
	}
	else
		tmp = -1;
	return (tmp);
}

int		put_img(t_env *env)
{
	static int	drawed = -1;
	static int	x;
	int			y;

	if (env->selected_button < 0 || !env->draw)
		return (ft_fill_img1(env));
	y = -1;
	while (++y < HEIGHT)
		ft_draw_pix(x, y, env);
	x++;
	if (x == WIDTH || (drawed != -1 && drawed != env->selected_button))
	{
		env->status = 1;
		reset_draw(env, -1);
		x = 0;
		put_button(env->selected_button, 135, env);
	}
	if (!env->fail)
		mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 50, 30);
	drawed = env->selected_button;
	return (0);
}

void	put_button(int selected_button, int x, t_env *e)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->wb, (x + 140 * i), 880);
		if (i == selected_button)
			mlx_put_image_to_window(e->mlx, e->win, e->gb, (x + 140 * i), 880);
		i++;
	}
}
