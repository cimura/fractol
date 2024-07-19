#include "fractal.h"

void print_usage(void)
{
  ft_putstr_fd("Usage:\n", 1);
  ft_putstr_fd("  ./fractal mandelbrot\n", 1);
  ft_putstr_fd("  ./fractal julia <real> <imaginary>\n", 1);
  ft_putstr_fd("  ./fractal burning_ship\n", 1);
  ft_putstr_fd("\nExamples:\n", 1);
  ft_putstr_fd("  ./fractal mandelbrot\n", 1);
  ft_putstr_fd("  ./fractal julia -0.4 0.6\n", 1);
  ft_putstr_fd("  ./fractal burning\n", 1);
}

int main(int argc, char **argv)
{
    t_fractal fractal;

    if (argc < 2)
    {
        ft_putstr_fd("Error: Not enough arguments\n\n", 1);
        print_usage();
        return (1);
    }
    fractal.name = argv[1];
     if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
        || (4 == argc && !ft_strncmp(argv[1], "julia", 5))
        || (2 == argc && !ft_strncmp(argv[1], "burning", 7)))
      {
        if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
        {
            fractal.julia_x = ft_atod(argv[2]);
            fractal.julia_y = ft_atod(argv[3]);
        }
      }
    else
    {
        ft_putstr_fd("Error: Invalid arguments\n\n");
        print_usage();
        return (1);
    }
  fractal_init();

    ft_putstr_fd("Controls:\n", 1);
    ft_putstr_fd("  Arrow keys: Move\n");
    ft_putstr_fd("  +/- : Zoom in/out\n");
    ft_putstr_fd("  ESC: Quit\n");

    mlx_loop(fractal.mlx_ptr);
    return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
