#include "render.h"
#include "math.h"

int calc_mandelbrot(t_engine *engine, int x, int y)
{
    double      re_temp;
    t_fractal   *fract;
    t_complex   z;
    t_complex   c;
    int         i;

    i = -1;
    z.re = 0;
    z.im = 0;
    fract = &engine->fractal;
    c.re = (x / fract->zoom) + fract->offset_x;
    c.im = (y / fract->zoom) + fract->offset_y;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c.re;
        z.im = 2 * z.re * z.im + c.im;
        z.re = re_temp;
    }
    return (i);
}

int calc_julia(t_engine *engine, int x, int y)
{
    double      re_temp;
    t_fractal   *fract;
    t_complex   z;
    t_complex   c;
    int         i;

    i = -1;
    fract = &engine->fractal;
    z.re = (x / fract->zoom) + fract->offset_x;
    z.im = (y / fract->zoom) + fract->offset_y;
    c.re = (fract->mouse_x / fract->zoom) + fract->offset_x;
    c.im = (fract->mouse_y / fract->zoom) + fract->offset_x;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c.re;
        z.im = 2 * z.re * z.im + c.im;
        z.re = re_temp;
    }
    return (i);
}

int calc_burning_ship(t_engine *engine, int x, int y)
{
    double      re_temp;
    t_fractal   *fract;
    t_complex   z;
    t_complex   c;
    int         i;

    i = -1;
    z.re = 0;
    z.im = 0;
    fract = &engine->fractal;
    c.re = (x / fract->zoom) + fract->offset_x;
    c.im = (y / fract->zoom) + fract->offset_y;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c.re;
        z.im = fabs(2 * z.re * z.im) + c.im;
        z.re = fabs(re_temp);
    }
    return (i);
}