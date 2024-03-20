/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:19:09 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/11 22:54:32 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_engine.h"
#include "utils.h"
#include "mlx.h"

void	change_fractal(int key, t_engine *engine)
{
	reset_engine(engine, MANDELBROT);
	if (key == KEY_TWO)
		engine->fractal.type = JULIA;
	else if (key == KEY_THREE)
		engine->fractal.type = BURNING_SHIP;
	else if (key == KEY_FOUR)
		engine->fractal.type = TRICORN;
	else if (key == KEY_FIVE)
		engine->fractal.type = MANDELBOX;
	else if (key == KEY_SIX)
		engine->fractal.type = CELTIC_MANDELBAR;
}

void	set_fractal_type(t_engine *engine, char *str)
{
	size_t	len;

	if (!engine || !str)
		return ;
	ft_strlower(str);
	len = ft_strlen(str);
	if (ft_strncmp(str, MANDELBROT_STR, len) == 0)
		engine->fractal.type = MANDELBROT;
	else if (ft_strncmp(str, JULIA_STR, len) == 0)
		engine->fractal.type = JULIA;
	else if (ft_strncmp(str, BURNING_SHIP_STR, len) == 0)
		engine->fractal.type = BURNING_SHIP;
	else if (ft_strncmp(str, TRICORN_STR, len) == 0)
		engine->fractal.type = TRICORN;
	else if (ft_strncmp(str, MANDELBOX_STR, len) == 0)
		engine->fractal.type = MANDELBOX;
	else if (ft_strncmp(str, CELTIC_MANDELBAR_STR, len) == 0)
		engine->fractal.type = CELTIC_MANDELBAR;
	else
		show_help();
}

void	reset_engine(t_engine *engine, int fractal_type)
{
	engine->fractal.type = fractal_type;
	engine->fractal.zoom = WIN_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.is_julia_lock = false;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.iterations = MIN_ITERATIONS;
}

void	init_engine(t_engine *engine, char *arg)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine || !arg)
		return ;
	reset_engine(engine, MANDELBROT);
	set_fractal_type(engine, arg);
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, \
												"Fractol project");
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->window || !engine->image.img_ptr)
	{
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		mlx_destroy_window(engine->mlx, engine->window);
		error_message("[MLX ERROR]: can't handle object creation!\n", 1);
	}
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr, \
								&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
}
