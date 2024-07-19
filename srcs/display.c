/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:48:45 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/19 21:07:51 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_zoom_level(t_fractal *fractal)
{
	char *zoom_str = "Zoom: ";
	char *zoom_level = ft_itoa(fractal->zoom);
	char *result = ft_strjoin(zoom_str, zoom_level);
	mlx_string_put(fractal->mlx_ptr, fractal->window_ptr, 10, 10, BLACK, result);
	free(zoom_level);
	free(result);
}