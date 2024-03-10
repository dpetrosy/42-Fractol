#include "render.h"

void	change_color(int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x300000;
	else if (key == KEY_W)
	    engine->fractal.color += 0x030000;
	else if (key == KEY_E)
	    engine->fractal.color += 0x003000;
	else if (key == KEY_R)
	    engine->fractal.color += 0x000300;
	else if (key == KEY_T)
	    engine->fractal.color += 0x000030;
	else if (key == KEY_Y)
	    engine->fractal.color += 0x000003;
	else if (key == KEY_A)
	    engine->fractal.color -= 0x300000;
	else if (key == KEY_S)
	    engine->fractal.color -= 0x030000;
	else if (key == KEY_D)
	    engine->fractal.color -= 0x003000;
	else if (key == KEY_F)
	    engine->fractal.color -= 0x000300;
	else if (key == KEY_G)
	    engine->fractal.color -= 0x000030;
	else if (key == KEY_H)
	    engine->fractal.color -= 0x000003;
}
void	change_view(int key, t_engine *engine)
{
    t_fractal *fractal;

    fractal = &engine->fractal;
	if (key == KEY_LEFT)
		fractal->offset_x -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->offset_x += VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_UP)
		fractal->offset_y -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_DOWN)
		fractal->offset_y += VIEW_CHANGE_SIZE / fractal->zoom;
}

void    set_pixel_color(t_engine *engine, int x, int y, int color)
{
    int line_len;
    int pixel_bits;
	int offset;

    if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
		return ;
    line_len = engine->image.line_len;
    pixel_bits = engine->image.pixel_bits;
    offset = (y * line_len) + ((pixel_bits / 8) * x);
    *(unsigned int *)(engine->image.addr_ptr + offset) = color;
}

void    draw_fractal(t_engine *engine)
{
	int	x;
	int	y;
	int	i;

    x = -1;
	mlx_clear_window(engine->mlx, engine->window);
    while (++x < WIN_SIZE)
    {
        y = -1;
        while (++y < WIN_SIZE)
		{
			if (engine->fractal.type == MANDELBROT_NUM)
				i = calc_mandelbrot(engine, x, y);
			else if (engine->fractal.type == JULIA_NUM)
			 	i = calc_julia(engine, x, y);
			else if (engine->fractal.type == BURNING_SHIP_NUM)
				i = calc_burning_ship(engine, x, y);
        	set_pixel_color(engine, x, y, (i * engine->fractal.color));
		}
    }
    mlx_put_image_to_window(engine->mlx, engine->window, engine->image.img_ptr, 0, 0);
}
