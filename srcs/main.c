/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:25:36 by cimy              #+#    #+#             */
/*   Updated: 2024/07/22 15:42:09 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void	print_usage(void)
{
	ft_putstr_fd(BLUE"Usage:\n"RESET, 1);
	ft_putstr_fd(GREEN"	./fractol mandelbrot\n", 1);
	ft_putstr_fd(GREEN"	./fractol julia <real> <imaginary>\n", 1);
	ft_putstr_fd(GREEN"	./fractol ship\n"RESET, 1);
	ft_putstr_fd(BLUE"\nExamples:\n"RESET, 1);
	ft_putstr_fd(GREEN"	./fractol mandelbrot\n", 1);
	ft_putstr_fd("	./fractol julia -0.4 0.6\n", 1);
	ft_putstr_fd("	./fractol ship\n\n"RESET, 1);
}

static void	print_controls(void)
{
	ft_putstr_fd(BLUE"Controls:\n"RESET, 1);
	ft_putstr_fd(YELLOW"  Arrow keys :  "RESET, 1);
	ft_putstr_fd("Move\n", 1);
	ft_putstr_fd(YELLOW"  +/-        :  "RESET, 1);
	ft_putstr_fd("Resultion up/down\n", 1);
	ft_putstr_fd(YELLOW"  ESC        :  "RESET, 1);
	ft_putstr_fd("Quit\n", 1);
	ft_putstr_fd(YELLOW"  Wheel      :  "RESET, 1);
	ft_putstr_fd("Zoom in/out\n", 1);
	ft_putstr_fd(YELLOW"  Space      :  "RESET, 1);
	ft_putstr_fd("Reset\n", 1);
}

static void	name_init(t_fractal *fractal, char **argv)
{
	fractal->name = argv[1];
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = ft_atod(argv[2]);
		fractal->julia_y = ft_atod(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2)
	{
		ft_putstr_fd(RED"Error: Not enough arguments\n\n"RESET, 1);
		print_usage();
		exit(EXIT_FAILURE);
	}
	else if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5))
		|| (2 == argc && !ft_strncmp(argv[1], "ship", 4)))
	{
		name_init(&fractal, argv);
		fractal_init(&fractal);
	}
	else
	{
		ft_putstr_fd(RED"Error: Invalid arguments\n\n"RESET, 1);
		print_usage();
		exit(EXIT_FAILURE);
	}
	return (print_controls(), mlx_loop(fractal.mlx_ptr), 0);
}
