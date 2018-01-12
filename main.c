/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:22:53 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 18:06:42 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rtv1.h"
#include "scene.h"
#include "libft.h"

int			error(char *error, char *spec, char *in)
{
	ft_putstr_fd("RT: Error: ", 2);
	if (!spec)
		ft_putendl_fd(error, 2);
	else
	{
		if (in)
		{
			ft_putstr_fd(error, 2);
			ft_putstr_fd(in, 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(spec, 2);
		}
		else
		{
			ft_putstr_fd(error, 2);
			ft_putendl_fd(spec, 2);
		}
	}
	return (0);
}

int			main(void)
{
	t_env	e;

	ft_mlx_init(&e, &e.img);
	mlx_put_image_to_window(e.mlx, e.win, e.rb, 977, 1130);
	put_button(e.selected_button, 135, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, ft_loop, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, put_img, &e);
	mlx_loop(e.mlx);
	return (0);
}
