/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:30:49 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/08 00:55:39 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_engine.h"
#include "render.h"
#include "events.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_engine engine;

	if (argc != 2)
		show_help();
	init_engine(&engine, argv[1]);
	draw_fractal(&engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_mouse_hook(engine.window, on_mouse_hook_event, &engine);
	mlx_hook(engine.window, 6, 1L << 6, on_mousemove_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
