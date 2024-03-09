#include "events.h"
#include "render.h"
#include "make_engine.h"
#include "mlx.h"

int	on_render_frame_event(t_engine *engine)
{
	draw_fractal(engine);
	mlx_do_sync(engine->mlx);
	return (0);
}

int	on_destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}

void change_fractal(int key, t_engine *engine)
{
	mlx_clear_window(engine->mlx, engine->window);
	reset_engine(engine, MANDELBROT_NUM);
	if (key == KEY_TWO)
		engine->fractal.type = JULIA_NUM;
}

int on_mouse_hook_event(int key, int x, int y, t_engine *engine)
{
	t_fractal *fractal;

	fractal = &engine->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * 1.3));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * 1.3));
		fractal->zoom *= 1.3;
		if (fractal->max_iterations < 256)
			++fractal->max_iterations;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / 1.3));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom / 1.3));
		fractal->zoom /= 1.3;
		if (fractal->max_iterations > -256)
			--fractal->max_iterations;
	}
	return (0);
}

int on_key_hook_event(int key, t_engine *engine)
{
	if ((key >= KEY_Q && key <= KEY_Y) || (key >= KEY_A && key <= KEY_H))
		change_color(key, engine);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		change_view(key, engine);
	else if (key >= KEY_ONE && key <= KEY_FIVE)
		change_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == JULIA_NUM)
		;
	//	lock_julia();
	else if (key == KEY_ZERO)
		reset_engine(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		on_destroy_event(engine);
    return (0);
}