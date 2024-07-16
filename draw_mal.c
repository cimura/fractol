#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 600

#define mid_x WIDTH / 2
#define mid_y HEIGHT / 2

#define RADIUS	100

int circle(int x, int y)
{
    int iter = 0;
	int X = (x - mid_x)*(x - mid_x);
	int Y = (y - mid_y)*(y - mid_y);
	if (X <= RADIUS * RADIUS - Y)
	{
		iter++;
	}
    return (iter);
}

// while (cabs(z) < 2 && iter < MAX_ITER) {
//         z = z * z + c;
//         iter++;
//     }

int shadow(int x, int y)
{
	int shadow = 0;
	
}


int main()
{
    void *mlx;
    void *win;
    void *img;
    int *data;
    int bpp, size_l, endian;
	int iter = 0;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Circle Set");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    data = (int *)mlx_get_data_addr(img, &bpp, &size_l, &endian);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
			int iter = circle(x, y);
			int color = (iter * 255) << 16;
            data[y * WIDTH + x] = color;
        }
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return 0;
}
