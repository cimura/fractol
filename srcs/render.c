/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:31:15 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/22 13:41:37 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_length) + (x * (img->bpp / 8));
		*(unsigned int *)(img->pixel_ptr + offset) = color;
	}
}

static bool	terminate(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		return (mandel(fractal));
	else if (!ft_strncmp(fractal->name, "julia", 5))
		return (julia(fractal));
	else if (!ft_strncmp(fractal->name, "ship", 4))
		return (burning_ship(fractal));
	return (true);
}

int	render_next_frame(t_fractal *fractal)
{
	fractal->count = 0;
	while (fractal->x < WIDTH)
	{
		if (!terminate(fractal))
		{
			mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr,
				fractal->img.img_ptr, 0, 0);
			break ;
		}
		fractal->y++;
		if (fractal->y >= HEIGHT)
		{
			fractal->y = 0;
			fractal->x++;
		}
	}
	if (fractal->x >= WIDTH)
	{
		mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr,
			fractal->img.img_ptr, 0, 0);
		fractal->x = 0;
		fractal->y = 0;
		return (0);
	}
	return (0);
}
