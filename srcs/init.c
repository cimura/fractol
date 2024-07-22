/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:32:21 by cimy              #+#    #+#             */
/*   Updated: 2024/07/22 15:45:33 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 15;
	fractal->out_judge = 30;
	fractal->mouse.shift_x = 0.0;
	fractal->mouse.shift_y = 0.0;
	fractal->mouse.zoom = 1.0;
	fractal->termination = 1000000;
}

static void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->window_ptr, key_handler, fractal);
	mlx_mouse_hook(fractal->window_ptr, mouse_handler, fractal);
	mlx_hook(fractal->window_ptr, 4, 0, mouse_press, fractal);
	mlx_hook(fractal->window_ptr, 5, 0, mouse_release, fractal);
	mlx_hook(fractal->window_ptr, 6, 0, mouse_move, fractal);
	mlx_hook(fractal->window_ptr, 6, 1L << 6, julia_track, fractal);
	mlx_hook(fractal->window_ptr, 17, 0, close_handler, fractal);
	mlx_loop_hook(fractal->mlx_ptr, render_next_frame, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (NULL == fractal->mlx_ptr)
		malloc_error();
	fractal->window_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->window_ptr)
		malloc_error();
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
		malloc_error();
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_length, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
