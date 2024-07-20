/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:20:42 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/20 11:08:23 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

bool	Mandel(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	init_condition(fractal, &z, &c);

	// fractal->termination *= fractal->zoom;
	// z.x = 0;
	// z.y = 0;
	// c.x = (map(fractal->x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	// c.y = (map(fractal->y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;

	i = 0;
	while (i < fractal->out_judge)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) - (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->out_judge);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return (true);
		}
		fractal->count++;
		i++;
	}
	my_pixel_put(fractal->x, fractal->y, &fractal->img, BLACK);
	return (true);
}

bool	Julia(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	init_condition(fractal, &z, &c);

	// fractal->termination *= fractal->zoom;
	// c.x = fractal->julia_x;
	// c.y = fractal->julia_y;
	// z.x = (map(fractal->x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	// z.y = (map(fractal->y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;

	i = 0;
	while (i < fractal->out_judge)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->out_judge);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return (true);
		}
		fractal->count++;
		i++;
	}
	my_pixel_put(fractal->x, fractal->y, &fractal->img, BLACK);
	return (true);
}

bool	burning_ship(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	init_condition(fractal, &z, &c);
	// fractal->termination *= fractal->zoom;
	// z.x = 0;
	// z.y = 0;
	// c.x = (map(fractal->x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	// c.y = (map(fractal->y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;

	i = 0;
	while (i < fractal->out_judge)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) - (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, WHITE, BLACK, fractal->out_judge);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return (true);
		}
		fractal->count++;
		i++;
	}
	my_pixel_put(fractal->x, fractal->y, &fractal->img, BLACK);
	return (true);
}

void	init_condition(t_fractal *fractal, t_complex *z, t_complex *c)
{
	fractal->termination *= fractal->zoom;
	if (!ft_strncmp(fractal->name, "mandelbrot", 10)
		|| !ft_strncmp(fractal->name, "burning", 7))
	{
		z->x = 0;
		z->y = 0;
		c->x = (map(fractal->x, -2, +2, WIDTH)
				* fractal->zoom) + fractal->shift_x;
		c->y = (map(fractal->y, +2, -2, HEIGHT)
				* fractal->zoom) + fractal->shift_y;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->x = fractal->julia_x;
		z->y = fractal->julia_y;
		c->x = (map(fractal->x, -2, +2, WIDTH)
				* fractal->zoom) + fractal->shift_x;
		c->y = (map(fractal->y, +2, -2, HEIGHT)
				* fractal->zoom) + fractal->shift_y;
	}
}
