/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:26:29 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/22 15:18:41 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		close_handler(fractal);
	else if (keycode == 123)
		fractal->mouse.shift_x -= (0.5 * fractal->mouse.zoom);
	else if (keycode == 124)
		fractal->mouse.shift_x += (0.5 * fractal->mouse.zoom);
	else if (keycode == 125)
		fractal->mouse.shift_y -= (0.5 * fractal->mouse.zoom);
	else if (keycode == 126)
		fractal->mouse.shift_y += (0.5 * fractal->mouse.zoom);
	else if (keycode == 27 && fractal->out_judge > 25)
		fractal->out_judge -= 15;
	else if (keycode == 24 && fractal->out_judge < 100)
		fractal->out_judge += 15;
	else if (keycode == 49)
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
