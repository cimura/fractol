/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:56:24 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/22 17:20:28 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <mlx.h>
# include <math.h>
# include "../srcs/libft/libft.h"

# define WIDTH 1600
# define HEIGHT 1200

# define _WHITE 0xFFFFFF
# define _BLACK 0x000000
# define _BLUE	0x0000FF
# define _RED	0xFF0000
# define _YELLOW 0xFFFF00

# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}				t_img;	

typedef struct s_mouse
{
	double	shift_x;
	double	shift_y;
	double	zoom;
}				t_mouse;

typedef struct s_fractal
{
	double	x;
	double	y;
	t_img	img;
	t_mouse	mouse;
	void	*mlx_ptr;
	void	*window_ptr;
	char	*name;
	double	escape_value;
	int		out_judge;
	int		termination;
	int		count;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

//*** init ***
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);

//*** math ***
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// *** render ***
void		my_pixel_put(int x, int y, t_img *img, int color);
int			render_next_frame(t_fractal *fractal);

// *** events ***
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

// *** mandel ***
bool		mandel(t_fractal *fractal);
bool		julia(t_fractal *fractal);
bool		burning_ship(t_fractal *fractal);

// *** util ***
double		ft_atod(const char *str);

#endif
