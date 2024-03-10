/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:37:52 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/08 00:38:28 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdbool.h>
# include "libft.h"
# include "keys.h"
# include "mlx.h"

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"
# define TRICORN_STR "tricorn"

# define WIN_SIZE 500
# define VIEW_CHANGE_SIZE 60
# define MIN_ITERATIONS 150
# define MAX_ITERATIONS 256
# define DEFAULT_COLOR 265
//# define DEFAULT_COLOR 0x040000

typedef struct s_pixel
{
    int x;
    int y;
}   t_pixel;

typedef struct s_complex
{
    double  re;
    double  im;
}   t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}   t_image;

typedef struct s_fractal
{
    int type;
    double zoom;
    double offset_x;
    double offset_y;
    double mouse_x;
    double mouse_y;
    u_int32_t color;
    bool is_julia_lock;
    int iterations;
}   t_fractal;

typedef struct s_engine
{
    void        *mlx;
	void        *window;
    t_image     image;
    t_fractal   fractal;
}   t_engine;

int calc_mandelbrot(t_engine *engine, int x, int y);
int calc_julia(t_engine *engine, int x, int y);
int calc_burning_ship(t_engine *engine, int x, int y);
int calc_tricorn(t_engine *engine, int x, int y);

#endif  /* FRACTAL_H */
