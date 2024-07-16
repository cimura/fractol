#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH	1600
#define HEIGHT	1200
#define SIZE	2000
#define	MAX_ITERATIONS 100

// #define EXIT_SUCCESS 1

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	zx;
	double	zy;
	double	cx;
	double	cy;

	double	x;
	double	y;

	double	zoom;

	double	offset_x;
	double	offset_y;

	int		max_iter;

	char	*name;

	int		color;

}	t_fractal;

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
		*(unsigned int *)dst = mlx_get_color_value(fractal->mlx, color);
	}
	// mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, x, y);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	// 53がEsc keyに対応?
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_image(fractal->mlx, fractal->img);
		exit (0);
	}
	return (0);
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	int	i;
	double	x_tmp;

	fractal->name = "mandel";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) - (WIDTH / (2.0 * fractal->zoom)) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) - (HEIGHT / (2.0 * fractal->zoom)) + fractal->offset_y;
	while (i < fractal->max_iter)
	{
		x_tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == fractal->max_iter)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x00FF00);
	else if (i % 3 == 0)
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * i*3));
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * i%16));
}

void	draw_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;

	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}


// int	render_next_frame(t_fractal *fractal)
// {
// 	if ()
// }

int	main(void)
{
	t_fractal	fractal;
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	fractal.addr = mlx_get_data_addr(fractal.img, &fractal.bits_per_pixel, &fractal.line_length, &fractal.endian);

	fractal.zoom = 300.0;
	fractal.offset_x = -0.5;
	fractal.offset_y = 0.0;
	fractal.max_iter = 100;
	fractal.color = 0x0FF000;

	draw_fractal(&fractal);
	// mlx_hook(fractal.win, 33, 1L << 17, close, &fractal.mlx);
	mlx_key_hook(fractal.win, key_hook, &fractal);

	// mlx_loop_hook(fractal.win, render_next_frame, &fractal);

	mlx_loop(fractal.mlx);

	// mlx_loop_hook(fractal.mlx, render_next_frame, &fractal);
	mlx_destroy_image(fractal.mlx, fractal.img);
	mlx_destroy_window(fractal.mlx, fractal.win);
	// mlx_destroy_display(fractal.mlx);
	free(fractal.mlx);
	return (0);
}
