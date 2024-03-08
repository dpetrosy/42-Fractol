#include <float.h>
#include "render.h"

void    set_pixel_color(t_engine *engine, int x, int y, int color)
{
	char	*pixel;

	pixel = engine->image.addr_ptr + (y * engine->image.line_length + x \
        * (engine->image.bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

void calculate_mandelbrot(t_engine *engine, t_fractal *fract, t_pixel *pixel)
{
    double      re_temp;
    t_complex   z;
    t_pixel     c;
    int         i;


    // testing
    fract->zoom = 1;
    fract->offset_x = 0;
    fract->offset_y = 0;
    fract->color = 156;


    i = -1;
    z.re = 0;
    z.im = 0;
    c.x = (pixel->x / fract->zoom) + fract->offset_x;
    c.y = (pixel->y / fract->zoom) + fract->offset_y;
    while (++i < MAX_ITERATIONS)
    {
        re_temp = z.re * z.re - z.im * z.im + c.x;
        z.im = 2. * z.re * z.im + c.x;
        z.re = re_temp;
        if (z.re * z.re + z.im * z.im >= DBL_MAX)
            break ;
    }
    if (i == MAX_ITERATIONS)
        set_pixel_color(engine, pixel->x, pixel->y, 0);
    else
        set_pixel_color(engine, pixel->x, pixel->y, (fract->color * (i % 255)));
}

void    draw_fractal(t_engine *engine)
{
    t_pixel pixel;

    pixel.x = -1;
    while (++pixel.x < WIN_SIZE)
    {
        pixel.y = -1;
        while (++pixel.y < WIN_SIZE)
            calculate_mandelbrot(engine, &engine->fractal, &pixel);
    }
    mlx_put_image_to_window(engine->mlx, engine->window, \
                        engine->image.img_ptr, 0, 0);
}
