#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "libft/libft.h"

#define WIDTH   1600
#define HEIGHT  1200
#define SIZE    2000
#define LOOP_LIMIT  40
#define MAX_ITERATIONS 10000000

typedef struct s_fractal
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;

    double  zx;
    double  zy;
    double  cx;
    double  cy;

    double  x;
    double  y;

    double  zoom;

    double  offset_x;
    double  offset_y;

    double  count;

    int     max_iter;

    char    *name;

    int     color;

    int     is_zoomed; // flag to indicate if zoom has changed
    int     mouse_x;   // mouse x position
    int     mouse_y;   // mouse y position

}   t_fractal;

typedef struct s_complex
{
    double  re;
    double  im;
}       t_complex;

t_complex complex_add(t_complex a, t_complex b)
{
    t_complex ans;

    ans.re = a.re + b.re;
    ans.im = a.im + b.im;
    return (ans);
}

t_complex complex_mul(t_complex a, t_complex b)
{
    t_complex ans;

    ans.re = a.re * b.re - a.im * b.im;
    ans.im = a.re * b.im + b.re * a.im;
    return (ans);
}

double complex_abs(t_complex n)
{
    return (n.re * n.re + n.im * n.im);
}

void put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
    char *mlx_data_addr;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        mlx_data_addr = fractal->addr + (y * fractal->line_length + x * (fractal->bpp / 8));
        *(unsigned int *)mlx_data_addr = color;
    }
}

int key_hook(int keycode, t_fractal *fractal)
{
    if (keycode == 53)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_image(fractal->mlx, fractal->img);
        fractal->mlx = NULL;
        exit(0);
    }
    if (keycode == 4)
    {
        char *zoom_str = "Help: ";
        mlx_string_put(fractal->mlx, fractal->win, 10, 100, 0xFFFFFF, "Esc -> Break");
    }
    return (0);
}

int Mandel(t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;

    z.re = 0;
    z.im = 0;//fractal->offset_x = (x / fractal->zoom) - (WIDTH / (2.0 * fractal->zoom)) + fractal->offset_x;
    c.re = (fractal->x / fractal->zoom) - (WIDTH / (2.0 * fractal->zoom)) + fractal->offset_x;
    c.im = (fractal->y / fractal->zoom) - (HEIGHT / (2.0 * fractal->zoom)) + fractal->offset_y;

    i = 0;
    while (i < LOOP_LIMIT && complex_abs(z) < 15.0)
    {
        z = complex_add(complex_mul(z, z), c);
        i++;
        fractal->count++;
        if (fractal->count > MAX_ITERATIONS + fractal->zoom*100)
            return (-1);
    }

    if (i == LOOP_LIMIT)
    {
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
    }
    else if (z.re * z.im > 0)
    {
        put_color_to_pixel(fractal, fractal->x, fractal->y, fractal->color * i);
    }
    else if (i % 2 == 0)
    {
        put_color_to_pixel(fractal, fractal->x, fractal->y, fractal->color + i);
    }
    else
        put_color_to_pixel(fractal, fractal->x, fractal->y, fractal->color - i);
    return (i);
}

void draw_zoom_level(t_fractal *fractal)
{
    char *zoom_str = "Zoom: ";
    char *zoom_level = ft_itoa(fractal->zoom);
    char *result = ft_strjoin(zoom_str, zoom_level);
    mlx_string_put(fractal->mlx, fractal->win, 10, 10, 0xFFFFFF, result);
    free(zoom_level);
    free(result);
}

int render_next_frame(t_fractal *fractal)
{
    int result;

    // if (fractal->is_zoomed)
    // {
    //     fractal->x = 0;
    //     fractal->y = 0;
    //     fractal->count = 0;
    //     fractal->is_zoomed = 0;
    // }

    while (1)
    {
        result = Mandel(fractal);
        if (result == -1)
        {
            mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
            // draw_zoom_level(fractal);
            fractal->count = 0;
            return (0);
        }
        else
        {
        fractal->y++;
        if (fractal->y >= HEIGHT)
        {
            fractal->y = 0;
            fractal->x++;
            if (fractal->x >= WIDTH)
            {
                mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
                draw_zoom_level(fractal);
                fractal->x = 0;
                fractal->count = 0;
                return (0);
            }
        }
        }
    }

    return (0);
}

int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
    if (button == 4)
    {
        fractal->zoom *= 1.1;
        fractal->offset_x = (x / fractal->zoom) - (WIDTH / (2.0 * fractal->zoom)) + fractal->offset_x;
        fractal->offset_y = (y / fractal->zoom) - (HEIGHT / (2.0 * fractal->zoom)) + fractal->offset_y;
    }
    else if (button == 5)
    {
        fractal->zoom /= 1.1;
        fractal->offset_x = (x / fractal->zoom) - (WIDTH / (2.0 * fractal->zoom)) + fractal->offset_x;
        fractal->offset_y = (y / fractal->zoom) - (HEIGHT / (2.0 * fractal->zoom)) + fractal->offset_y;
    }

    // fractal->is_zoomed = 1;
    fractal->mouse_x = x;
    fractal->mouse_y = y;
    return (0);
}

int close_win(t_fractal *fractal)
{
    mlx_destroy_window(fractal->mlx, fractal->win);
    mlx_destroy_image(fractal->mlx, fractal->img);
    exit(0);
}

int main(void)
{
    t_fractal fractal;
    fractal.mlx = mlx_init();
    fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "Mandel Set");
    fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
    fractal.addr = mlx_get_data_addr(fractal.img, &fractal.bpp, &fractal.line_length, &fractal.endian);

    fractal.zoom = 300.0;
    fractal.offset_x = -0.5;
    fractal.offset_y = 0.0;
    fractal.max_iter = 100;
    fractal.color = 0x0F000FF2;
    fractal.x = 0;
    fractal.y = 0;
    fractal.count = 0;
    fractal.is_zoomed = 0;
    fractal.mouse_x = 0;
    fractal.mouse_y = 0;

    mlx_key_hook(fractal.win, key_hook, &fractal);
    mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
    mlx_hook(fractal.win, 17, 0, close_win, &fractal);
    mlx_loop_hook(fractal.mlx, render_next_frame, &fractal);
    mlx_loop(fractal.mlx);

    mlx_destroy_image(fractal.mlx, fractal.img);
    mlx_destroy_window(fractal.mlx, fractal.win);
    free(fractal.mlx);
    return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}