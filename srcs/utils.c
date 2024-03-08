#include "utils.h"
#include "events.h"

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

void    show_help()
{
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("-------------------Let me help you!-------------------\n", 1);
    ft_putstr_fd("Usage:  ./fractol [mandelbrot / julia / burning_ship /\n", 1);
    ft_putstr_fd("                   buffalo /\n", 1);
    ft_putstr_fd("                   heart_mandelbrot /\n", 1);
    ft_putstr_fd("                   celtic_mandelbrot /\n", 1);
    ft_putstr_fd("                   tricorn /\n", 1);
    ft_putstr_fd("                   burning_ship_fifth /\n", 1);
    ft_putstr_fd("                   perpendicular_burning_ship /\n", 1);
    ft_putstr_fd("                   celtic_mandelbar]\n", 1);
    ft_putstr_fd("\ne.g: ./fractol mandelbrot\n\n", 1);
    ft_putstr_fd("-----------------------KEYBOARD-----------------------\n", 1);
    ft_putstr_fd("\nPress ESC to close the window\n", 1);
    ft_putstr_fd("Press one of [0-9] to move to another fractal\n", 1);
    ft_putstr_fd("Press one of [Q-Y] keys to change the color of fractal\n", 1);
    ft_putstr_fd("Press one of [A-H] keys to change the color of fractal\n", 1);
    ft_putstr_fd("Press L to lock Julia's fractal\n", 1);
    ft_putstr_fd("Press the arrow keys to change the viewpoint\n", 1);
    ft_putstr_fd("Press Zero on the numpad to reset the fractal\n",1);
    ft_putstr_fd("Use mouse scroll to zoom in and out of the fractal\n\n", 1);
    exit(EXIT_SUCCESS);
}

char *get_fractal_type(char *str)
{
    size_t  len;

    len = ft_strlen(str);
    if (ft_strncmp(str, MANDELBROT, len) == 0)
        return (MANDELBROT);
    if (ft_strncmp(str, JULIA, len) == 0)
        return (JULIA);
    return (NULL);
}

void    init_engine(t_engine *engine, char *arg)
{
    int bits_per_pixel;
	int line_length;
	int endian;

    engine->fractal.type = get_fractal_type(arg);
    if (!engine->fractal.type)
        show_help();
    engine->mlx = mlx_init();
    if (!engine->mlx)
        error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, \
                                                    "Fractol project");
    engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
    if (!engine->window || !engine->image.img_ptr)
	{
		on_destroy_event(engine);
		error_message("[MLX ERROR]: can't handle object creation!\n", 1);
	}
    engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr, \
                    &bits_per_pixel, &line_length, &endian);
    engine->image.bits_per_pixel = bits_per_pixel;
    engine->image.line_length = line_length;
    engine->image.endian = endian;
}
