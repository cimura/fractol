/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:33:15 by cimy              #+#    #+#             */
/*   Updated: 2024/07/21 11:22:25 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static int	setup(const char *str, double *fraction,
						double *divisor)
{
	int	sign;

	sign = 1;
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

static double	inner_handler(const char *str, bool now_fraction,
	double divisor, double fraction)
{
	double	result;

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
	return (result);
}

double	ft_atod(const char *str)
{
	double	result;
	double	divisor;
	double	fraction;
	int		sign;
	bool	now_fraction;

	now_fraction = false;
	sign = setup(str, &fraction, &divisor);
	result = inner_handler(str, now_fraction, divisor, fraction);
	return (result * sign);
}
