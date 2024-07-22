/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:33:15 by cimy              #+#    #+#             */
/*   Updated: 2024/07/22 15:42:51 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static bool	is_valid_format(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str != '0')
		return (false);
	str++;
	if (*str != '.')
		return (false);
	str++;
	if (!(*str >= '0' && *str <= '9'))
		return (false);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

static void	format_error(void)
{
	ft_putstr_fd("Error: Invalid format. Expected format is '0.xxx'\
			where 'xxx' are digits.\n", 2);
	exit(EXIT_FAILURE);
}

static int	setup(const char *str, double *fraction,
						double *divisor)
{
	int	sign;

	sign = 1;
	*fraction = 0.0;
	*divisor = 1.0;
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

	result = 0.0;
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
	if (!is_valid_format(str))
		format_error();
	sign = setup(str, &fraction, &divisor);
	result = inner_handler(str, now_fraction, divisor, fraction);
	return (result * sign);
}
