# include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5))
		|| (2 == argc && !ft_strncmp(argv[1], "burning", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atod(argv[2]);
			fractal.julia_y = ft_atod(argv[3]);
		}
		fractal_init(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}