#include "render.h"

void calculate_mandelbrot(t_engine *engine, t_fractal *fract, t_pixel *pixel)
{
    double      re_temp;
    t_complex   z;
    t_complex   c;
    int         i;

    i = 0;
    z.re = 0;
    z.im = 0;
    c.re = (pixel->x / fract->zoom) + fract->offset_x;
    c.im = (pixel->y / fract->zoom) + fract->offset_y;
    while ((z.re * z.re + z.im * z.im) < 4 && i < fract->max_iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c.re;
        z.im = 2 * z.re * z.im + c.im;
        z.re = re_temp;
        ++i;
    }
    if (i == fract->max_iterations)
        set_pixel_color(engine, pixel->x, pixel->y, 0);
    else
        set_pixel_color(engine, pixel->x, pixel->y, (fract->color * i));
}