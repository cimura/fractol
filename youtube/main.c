# include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal fractal;
	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		// fractal.julia_x = ft_atod(argv[2]);
		// fractal.julia_y = ft_atod(argv[3]); 
		fractal.julia_x = -0.8;
		fractal.julia_y = 0.1544;

		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	// free(fractal.mlx_ptr);
	// free(fractal.window_ptr);
	// free(fractal.img.img_ptr);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}