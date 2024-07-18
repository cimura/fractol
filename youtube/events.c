#include "fractal.h"

// keycode
// esc -> 53, space -> 49

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
	fractal->mlx_ptr = NULL;
	// free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		close_handler(fractal);
	if (keycode == 123) // left
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == 124) // right
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == 125) // down
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keycode == 126) // up
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == 27) // minus
		fractal->max_iterations += 10;
	else if (keycode == 24) // plus
		fractal->max_iterations -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 4)
	{
		fractal->zoom *= 1.05;
	}
	// printf("%d\n", button);
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = map(x, -2, +2, 0, WIDTH) * fractal->zoom + fractal->shift_x;
		fractal->julia_y = map(y, +2, -2, 0, HEIGHT) * fractal->zoom + fractal->shift_y;
	}
	fractal_render(fractal);
	return (0);
}