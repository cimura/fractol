// #include "fractal.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
static void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, &*s, ft_strlen(s));
}
static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	print_usage(void)
{
	ft_putstr_fd(BLUE"Usage:\n"RESET, 1);
	ft_putstr_fd(GREEN"	./fractal mandelbrot\n", 1);
	ft_putstr_fd(GREEN"	./fractal julia <real> <imaginary>\n", 1);
	ft_putstr_fd(GREEN"	./fractal burning_ship\n"RESET, 1);	
	ft_putstr_fd(BLUE"\nExamples:\n"RESET, 1);
	ft_putstr_fd(GREEN"	./fractal mandelbrot\n", 1);
	ft_putstr_fd("	./fractal julia -0.4 0.6\n", 1);
	ft_putstr_fd("	./fractal burning_ship\n\n"RESET, 1);
}

void	print_controls(void)
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


int	main(int argc, char **argv)
{
  char *alloc = malloc(1);
  // alloc[0] = 'A';
  // return (0);
	if (argc < 2)
	{
		ft_putstr_fd(RED"Error: Not enough arguments\n\n"RESET, 1);
		print_usage();
		exit(EXIT_FAILURE);
	}
	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5))
		|| (2 == argc && !ft_strncmp(argv[1], "burning", 7)))
	{
		printf("hello\n");
	}
	else
	{
		ft_putstr_fd(RED"Error: Invalid arguments\n\n"RESET, 1);
		print_usage();
		exit(EXIT_FAILURE);
	}
	print_controls();
	return (0);
}
