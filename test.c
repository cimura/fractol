#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 1600
#define HEIGHT 1200
#define MAX_ITERATIONS 10000000

typedef struct s_fractal
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    double zx;
    double zy;
    double cx;
    double cy;
    int x;
    int y;
    double zoom;
    double offset_x;
    double offset_y;
    int max_iter;
    char *name;
    int color;
    int iteration;
    int pixel_index;
    int mouse_x;
    int mouse_y;
} t_fractal;

void put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
    char *dst;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
        *(unsigned int *)dst = mlx_get_color_value(fractal->mlx, color);
    }
}

int key_hook(int keycode, t_fractal *fractal)
{
    if (keycode == 53)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_image(fractal->mlx, fractal->img);
        exit(0);
    }
    return (0);
}

int	close_up(int mouse_code, int x, int y, t_fractal *fractal)
{
	double zoom_factor;
	if (mouse_code == 4)
    {
        zoom_factor = 1.2;
    }
	else if (mouse_code == 5)
	{
		zoom_factor = 0.8;
	}
	else
		return (0);
	double new_zoom = fractal->zoom / zoom_factor;
    double new_offset_x = fractal->offset_x + (fractal->mouse_x - WIDTH / 2) / fractal->zoom * (1 - 1 / zoom_factor);
    double new_offset_y = fractal->offset_y + (fractal->mouse_y - HEIGHT / 2) / fractal->zoom * (1 - 1 / zoom_factor);

    fractal->zoom = new_zoom;
    fractal->offset_x = new_offset_x;
    fractal->offset_y = new_offset_y;
    fractal->pixel_index = 0;

	mlx_clear_window(fractal->mlx, fractal->win);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);

	return (0);
}

int calculate_mandelbrot(t_fractal *fractal)
{
    double x_tmp;
    fractal->name = "mandel";
    fractal->zx = 0.0;
    fractal->zy = 0.0;
    fractal->cx = (fractal->x / fractal->zoom) - (WIDTH / (2.0 * fractal->zoom)) + fractal->offset_x;
    fractal->cy = (fractal->y / fractal->zoom) - (HEIGHT / (2.0 * fractal->zoom)) + fractal->offset_y;
    fractal->iteration = 0;
    while (fractal->iteration < fractal->max_iter)
    {
		// マンデルブロ集合を複素数を使わずに書き直したもの
        x_tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
        fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
        fractal->zx = x_tmp;
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= __DBL_MAX__)
            break;
        fractal->iteration++;
        if (fractal->iteration == MAX_ITERATIONS)
            return 0;
    }
    if (fractal->iteration == fractal->max_iter)
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * fractal->iteration));
    return 1;
}

int render_next_frame(t_fractal *fractal)
{
    int i;

    i = 0;
    while (i < MAX_ITERATIONS)
    {
        if (fractal->pixel_index >= WIDTH * HEIGHT)
        {
            mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
            return 0;
        }
        fractal->x = fractal->pixel_index % WIDTH;
        fractal->y = fractal->pixel_index / WIDTH;
        if (!calculate_mandelbrot(fractal))
            return 0;
        fractal->pixel_index++;
        i++;
    }
    return 0;
}


int main(void)
{
    t_fractal fractal;
    fractal.mlx = mlx_init();
    fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
    fractal.addr = mlx_get_data_addr(fractal.img, &fractal.bits_per_pixel, &fractal.line_length, &fractal.endian);
    fractal.zoom = 300.0;
    fractal.offset_x = -0.5;
    fractal.offset_y = 0.0;
    fractal.max_iter = 100;
    fractal.color = 0x00FFFF00;
    fractal.pixel_index = 0;
    mlx_key_hook(fractal.win, key_hook, &fractal);

    mlx_loop_hook(fractal.mlx, render_next_frame, &fractal);
	mlx_mouse_hook(fractal.win, close_up, &fractal);
    mlx_loop(fractal.mlx);

    mlx_destroy_image(fractal.mlx, fractal.img);
    mlx_destroy_window(fractal.mlx, fractal.win);
    // mlx_destroy_display(fractal.mlx);
    free(fractal.mlx);

    return (0);
}