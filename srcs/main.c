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

#include "fractal.h"
#include "utils.h"
#include "events.h"

int	main(int argc, char **argv)
{
	t_engine engine;

	if (argc != 2)
		show_help();
	init_engine(&engine, argv[1]);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_loop_hook(engine.mlx, on_render_frame_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
