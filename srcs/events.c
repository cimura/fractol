#include "fractal.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
	fractal->mlx_ptr = NULL;
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		close_handler(fractal);
	if (keycode == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == 125)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keycode == 126)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == 27 && fractal->out_judge < 100)
		fractal->out_judge += 15;
	else if (keycode == 24 && fractal->out_judge > 25)
		fractal->out_judge -= 15;
	else if (keycode == 49)
		data_init(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
	{
		fractal->shift_x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->shift_y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal->zoom *= 0.90;
	}
	else if (button == 4)
	{
		fractal->shift_x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->shift_y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal->zoom *= 1.1;
	}
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = map(x, -2, +2, 0, WIDTH) * fractal->zoom + fractal->shift_x;
		fractal->julia_y = map(y, +2, -2, 0, HEIGHT) * fractal->zoom + fractal->shift_y;
	}
	return (0);
}

int	render_next_frame(t_fractal *fractal)
{
	while (1)
	{
		if (!Terminate(fractal))
		{
			mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr, fractal->img.img_ptr, 0, 0);
			draw_zoom_level(fractal);
			fractal->count = 0;
			return (0);
		}
		else
		{
			fractal->y++;
			if (fractal->y >= HEIGHT)
			{
				fractal->y = 0;
				fractal->x++;
				if (fractal->x >= WIDTH)
				{
					draw_zoom_level(fractal);
					mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr, fractal->img.img_ptr, 0, 0);
					fractal->x = 0;
					fractal->count = 0;
					return (0);
				}
			}
		}
	}
	return	(0);
}

bool	Terminate(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		return (Mandel(fractal));
	else if (!ft_strncmp(fractal->name, "julia", 5))
		return (Julia(fractal));
	else if (!ft_strncmp(fractal->name, "burning", 5))
		return (burning_ship(fractal));
	return (true);
}