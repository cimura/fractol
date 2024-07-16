#include <libc.h>
#include <mlx.h>

#define LOOP_LIMIT 100
#define	WIDTH	1600
#define	HEIGHT	1200

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;

	double	x;
	double	y;
	char	*addr;

	int		max_iter;
}	t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}		t_complex;

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	ans;

	ans.re = a.re + b.re;
	ans.im = a.im + b.im;
	return (ans);
}

t_complex	complex_mul(t_complex a, t_complex b)
{
	t_complex	ans;

	ans.re = a.re * b.re - a.im * b.im;
	ans.im = a.re * b.im + b.re * a.im;
	return (ans);
}

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	double	dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = 1000 + (y * fractal->x + x * (fractal->y / 8));
		dst = color;
	}
}

int	mandelbrot(double x, double y)
{
	t_complex	c = {x, y};
	t_complex	z = {0, 0};
	int			i;

	i = 0;
	while (i < LOOP_LIMIT)
	{
		z = complex_add(complex_mul(z, z), c);
		i++;
	}
	return (i);
}

#define SIZE_X 42
#define SIZE_Y 21

void	draw(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = -SIZE_Y;
	while (fractal->y <= SIZE_Y * 1)
	{
		fractal->x = -1.5*SIZE_X;
		while (fractal->x <= SIZE_X * 1.5)
		{
			int n = mandelbrot(fractal->x, fractal->y);
			if (n % 2 == 0)
				put_color_to_pixel(fractal, fractal->x, fractal->y, 0x0FFFFF);
			else if (n == fractal->max_iter)
				put_color_to_pixel(fractal, fractal->x, fractal->y, 0x00FF00);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

int	main(void)
{
	t_fractal fractal;

	fractal.max_iter = 100;

	fractal.mlx = mlx_init();
	fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "MANDEl");

	draw(&fractal);

	mlx_loop(fractal.mlx);
}