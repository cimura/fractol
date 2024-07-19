# include "fractal.h"

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

static int	setup(const char *str, double *result, double *fraction,
						double *divisor)
{
	int	sign;

	sign = 1;
	*result = 0.0;
	*fraction = 0.0;
	*divisor = 1.0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (sign);
}

double	ft_atod(const char *str)
{
	double	result;
	double	divisor;
	double	fraction;
	int		sign;
	bool	now_fraction;

	now_fraction = false;
	sign = setup(str, &result, &fraction, &divisor);
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			if (now_fraction)
			{
				divisor *= 10.0;
				fraction = fraction * 10.0 + (*str - '0');
			}
			else
				result = result * 10.0 + (*str - '0');
		}
		else if (*str == '.')
			now_fraction = true;
		str++;
	}
	result += fraction / divisor;
	return (result * sign);
}

