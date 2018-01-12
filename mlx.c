/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:23:26 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 18:38:53 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "rtv1.h"

void		ft_mlx_init(t_env *e, t_vimg *img)
{
	int		width1;
	int		height1;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH + 100, HEIGHT + 500, "Raytracer");
	e->draw = 0;
	e->status = 1;
	e->selected_button = -1;
	e->fail = 0;
	e->wb = mlx_xpm_file_to_image(e->mlx, "blanc.xpm", &width1, &height1);
	e->rb = mlx_xpm_file_to_image(e->mlx, "rouge.xpm", &width1, &height1);
	e->gb = mlx_xpm_file_to_image(e->mlx, "vert.xpm", &width1, &height1);
	e->owl = mlx_xpm_file_to_image(e->mlx, "hibou.xpm", &width1, &height1);
	e->black = mlx_xpm_file_to_image(e->mlx, "noir.xpm", &width1, &height1);
	img->ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	img->pxl = mlx_get_data_addr(img->ptr, &img->bpp, &img->ln, &img->nd);
	e->l_obj = NULL;
	e->l_spot = NULL;
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	static int	selected_button = -1;
	int			tmp;

	(void)button;
	tmp = which_position(x, y, 0, e);
	if (tmp == selected_button)
	{
		e->draw = 0;
		selected_button = -1;
		e->selected_button = selected_button;
	}
	else if (tmp != -1)
	{
		reset_draw(e, -1);
		e->draw = 1;
		selected_button = tmp;
		e->selected_button = selected_button;
		ft_get_selected_scene(e);
	}
	put_button(e->selected_button, 135, e);
	return (0);
}

int			ft_loop(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 50, 30);
	mlx_put_image_to_window(e->mlx, e->win, e->rb, 977, 1130);
	put_button(e->selected_button, 135, e);
	ft_fill_img1(e);
	return (0);
}

int			key_hook(int key, t_env *e)
{
	(void)e;
	if (key == 65307)
	{
		mlx_destroy_image(e->mlx, e->img.ptr);
		ft_del(e);
		exit(0);
	}
	return (0);
}
