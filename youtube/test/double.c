/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:29:51 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/19 16:38:10 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <xlocale.h>
#include <stdbool.h>
#include <limits.h>

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

int main(void) {
	const char *num = "1.1.23";
	printf("%f\n", ft_atod(num));
}