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

double	ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = decide_sign(str, &i);
	result = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign > 0)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}