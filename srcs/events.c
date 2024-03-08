#include "events.h"
#include "render.h"
#include "utils.h"

int	on_render_frame_event(t_engine *engine)
{
	draw_fractal(engine);
	//mlx_do_sync(engine->mlx);
	return (0);
}

int	on_destroy_event(t_engine *engine)
{
	mlx_destroy_window(engine->mlx, engine->window);
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	exit(0);
}

int on_key_hook_event(int key, t_engine *engine)
{
    (void)key;
    (void)engine;
    ft_putstr_fd("Barev ape\n", 1);
    return (0);
}