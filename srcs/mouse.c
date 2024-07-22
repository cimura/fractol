/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:02:24 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/22 15:43:43 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	mouse_press(int button, int x, int y, t_fractal *fractal)
{
	if (button == 1)
	{
		fractal->mouse.is_pressed = 1;
		fractal->mouse.prev_x = x;
		fractal->mouse.prev_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 1)
		fractal->mouse.is_pressed = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fractal *fractal)
{
	int	dx;
	int	dy;

	if (fractal->mouse.is_pressed)
	{
		dx = x - fractal->mouse.prev_x;
		dy = y - fractal->mouse.prev_y;
		fractal->mouse.prev_x = x;
		fractal->mouse.prev_y = y;
		fractal->mouse.shift_x += dx * fractal->mouse.zoom;
		fractal->mouse.shift_y += dy * fractal->mouse.zoom;
		// render_next_frame(fractal);
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
