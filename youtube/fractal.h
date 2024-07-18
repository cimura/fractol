/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:56:24 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/18 18:17:31 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 1600
# define HEIGHT 1200

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define ORANGE 0xFFA500


# include "../libft/libft.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}				t_img;	

typedef struct s_fractal
{
	t_img	img;
	void	*mlx_ptr;
	void	*window_ptr;
	char	*name;
	double	escape_value;
	int		max_iterations; // affect image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
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

//*** math ***
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			decide_sign(const char *str, int *i);
double		ft_atod(const char *str);

// *** render ***
void	fractal_render(t_fractal *fractal);

// *** events ***
int	key_handler(int keycode, t_fractal *fractal);
int	close_handler(t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);