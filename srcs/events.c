/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:26:29 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/22 22:22:41 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void	color_change(int keycode, t_fractal *fractal)
{
	if (keycode == XK_minus && fractal->out_judge > 25)
	{
		if (!ft_strncmp(fractal->name, "julia", 5))
			fractal->julia_color = _RED;
		else
			fractal->out_judge -= 15;

	}
	else if (keycode == XK_equal && fractal->out_judge < 100)
	{
		if (!ft_strncmp(fractal->name, "julia", 5))
			fractal->julia_color = _YELLOW;
		else
			fractal->out_judge += 15;
	}
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == XK_minus || keycode == XK_equal)
		color_change(keycode, fractal);
	else if (keycode == XK_Escape)
		close_handler(fractal);
	else if (keycode == XK_Left)
		fractal->mouse.shift_x -= (0.5 * fractal->mouse.zoom);
	else if (keycode == XK_Right)
		fractal->mouse.shift_x += (0.5 * fractal->mouse.zoom);
	else if (keycode == XK_Down)
		fractal->mouse.shift_y -= (0.5 * fractal->mouse.zoom);
	else if (keycode == XK_Up)
		fractal->mouse.shift_y += (0.5 * fractal->mouse.zoom);
	else if (keycode == XK_space)
		data_init(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = map(x, -2, +2, WIDTH)
			* fractal->mouse.zoom + fractal->mouse.shift_x;
		fractal->julia_y = map(y, +2, -2, HEIGHT)
			* fractal->mouse.zoom + fractal->mouse.shift_y;
	}
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
	{
		fractal->mouse.shift_x += (map(x, -2, 2, WIDTH)
				* fractal->mouse.zoom) / 3;
		fractal->mouse.shift_y += (map(y, 2, -2, HEIGHT)
				* fractal->mouse.zoom) / 3;
		fractal->mouse.zoom *= 0.90;
	}
	else if (button == 4)
	{
		fractal->mouse.shift_x += (map(x, -2, 2, WIDTH)
				* fractal->mouse.zoom) / 3;
		fractal->mouse.shift_y += (map(y, 2, -2, HEIGHT)
				* fractal->mouse.zoom) / 3;
		fractal->mouse.zoom *= 1.1;
	}
	return (0);
}
