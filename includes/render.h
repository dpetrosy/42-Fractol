#ifndef RENDER_H
# define RENDER_H

# include "fractal.h"

void    set_pixel_color(t_engine *engine, int x, int y, int color);
void	change_color(int key, t_engine *engine);
void	change_view(int key, t_engine *engine);
void    draw_fractal(t_engine *engine);

#endif  /* RENDER_H */