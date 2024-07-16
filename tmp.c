#include <libc.h>
#include <string.h>

typedef struct {
	double	re;
	double	im;
}	t_complex;

t_complex	complex_add(t_complex a, t_complex b)
{
	//t_complex	ans;
	//ans.re = a.re + b.re;
	//ans.im = a.im + b.im;
	//return ans;
	return (t_complex){a.re + b.re, a.im + b.im};
}
t_complex	complex_mul(t_complex a, t_complex b)
{
	t_complex	ans;
	ans.re = a.re * b.re - a.im * b.im;
	ans.im = a.im * b.re + a.re * b.im;
	return ans;
}
double	complex_abs(t_complex n)
{
	return n.re * n.re + n.im * n.im;
}


#define LOOP_LIMIT 100

// returns how fast (x+yi) diverges
int	mandelbrot(double x, double y)
{
	t_complex c = {x,y};
	t_complex z = {0,0};
	int	i;
	for (i = 0; i < LOOP_LIMIT && complex_abs(z) < 10; i++)
	{
		z = complex_add(complex_mul(z,z), c);
	}
	return i;
}
int	julia(double x, double y)
{
	t_complex c = {-0.12,0.48};
	t_complex z = {x,y};
	int	i;
	for (i = 0; i < LOOP_LIMIT && complex_abs(z) < 4; i++)
	{
		z = complex_add(complex_mul(z,z), c);
	}
	return i;
}

int	burning(double x, double y)
{
	t_complex	c = {};
	return (0);
}

void	put_pixel(int n)
{
	if (n % 3 == 0)
		printf("\x1b[31m%c", " .,:;x>++@"[n%10]);
	else if (n % 3 == 1)
		printf("\x1b[32m%c", " .,:;x>++@"[n%10]);
	else
		printf("\x1b[34m%c", " .,:;x>++@"[n%10]);
}

double SIZE_X = 70, SIZE_Y = 35;
void	draw(int flag)
{
	int	n;
	// 1 >= y >= -1
	for (double y = SIZE_Y * 1; y >= SIZE_Y * -1; y-=1)
	{
		// -1.5 <= x <= 1.5
		for (double x = SIZE_X * -1.5; x <= SIZE_X * 1.5; x+=1)
		{
			if (flag == 0)
				n = mandelbrot(x/SIZE_X, y/SIZE_Y);
			else if (flag == 1)
				n = julia(x/SIZE_X, y/SIZE_Y);
			put_pixel(n);
		}
		putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		SIZE_X = atof(argv[1]), SIZE_Y = atof(argv[2]);
		if (strncmp(argv[3], "julia", 6) == 0)
			draw(1);
		else if (strncmp(argv[3], "mandel", 7) == 0)
			draw(0);
	}
	else
		printf("Usage ./a.out <SIZE_X> <SIZE_X> name(julia or mandel)\n");
}