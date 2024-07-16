#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <libc.h>

#define WIDTH 1600
#define HEIGHT 1200
#define MAX_ITER 100

typedef struct s_vars
{
    void    *mlx;
    void    *win;
    void    *img;
    int    *data;
}              t_vars;

int mandelbrot(double real, double imag)
{
    int iter = 0;
    double complex z = 0;
    double complex c = real + imag * I;

    while (cabs(z) < 2 && iter < MAX_ITER) {
        z = z * z * z * z+ c;
        iter++;
    }
    return iter;
}

int key_hook(int keycode, void *param)
{
    // 53がEsc keyに対応?
    if (keycode == 53)
    {
        mlx_destroy_window(param, param);
        exit(0);
    }
    return (0);
}

// int close_hook(void *param)
// {
//     mlx_destroy_image(param, param);
//     exit(0);
//     return (0);
// }

int up(int keycode, void *param)
{
    if (keycode == 1)
    {
        mlx_destroy_window(param, param);
        exit(0);
    }
    return (0);
}

int main()
{
    t_vars  vars;
    int bpp, size_l, endian;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
    vars.data = (int *)mlx_get_data_addr(vars.img, &bpp, &size_l, &endian);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
            int iter = mandelbrot(real, imag);
            int color = (iter == MAX_ITER) ? 0 : (iter * 255 / MAX_ITER) << 16;
            vars.data[y * WIDTH + x] = color;
        }
    }

    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);

    mlx_key_hook(vars.win, key_hook, vars.mlx);
    // mlx_key_hook(vars.win, close_hook, vars.mlx);

    mlx_loop(vars.mlx);

    return 0;
}
