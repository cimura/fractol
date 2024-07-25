/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:20:42 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/22 22:14:00 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void	init_condition(t_fractal *fractal, t_complex *z, t_complex *c)
{
	fractal->termination *= fractal->mouse.zoom;
	if (!ft_strncmp(fractal->name, "mandelbrot", 10)
		|| !ft_strncmp(fractal->name, "ship", 4))
	{
		z->x = 0;
		z->y = 0;
		c->x = (map(fractal->x, -2, +2, WIDTH)
				* fractal->mouse.zoom) + fractal->mouse.shift_x;
		c->y = (map(fractal->y, +2, -2, HEIGHT)
				* fractal->mouse.zoom) + fractal->mouse.shift_y;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->x = (map(fractal->x, -2, +2, WIDTH)
				* fractal->mouse.zoom) + fractal->mouse.shift_x;
		z->y = (map(fractal->y, +2, -2, HEIGHT)
				* fractal->mouse.zoom) + fractal->mouse.shift_y;
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
}

bool	mandel(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	init_condition(fractal, &z, &c);
	i = 0;
	while (i < fractal->out_judge)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) - (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, _BLACK, _WHITE, fractal->out_judge);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return (true);
		}
		fractal->count++;
		i++;
	}
	if (z.x * z.y > 0)
		color = map(i, _YELLOW, _WHITE, fractal->out_judge);
	my_pixel_put(fractal->x, fractal->y, &fractal->img, _BLACK);
	return (true);
}

bool	julia(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	init_condition(fractal, &z, &c);
	i = 0;
	while (i < fractal->out_judge)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, _BLACK, _BLUE, fractal->out_judge);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return (true);
		}
		fractal->count++;
		i++;
	}
	my_pixel_put(fractal->x, fractal->y, &fractal->img, fractal->julia_color);
	return (true);
}

bool	burning_ship(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	init_condition(fractal, &z, &c);
	c.y = -c.y;
	i = 0;
	while (i < fractal->out_judge)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) - (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, _WHITE, _BLACK, fractal->out_judge);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return (true);
		}
		fractal->count++;
		i++;
	}
	my_pixel_put(fractal->x, fractal->y, &fractal->img, _BLACK);
	return (true);
}
