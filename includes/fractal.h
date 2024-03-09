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

# include "libft.h"
# include "keys.h"
# include "mlx.h"

# define MANDELBROT "mandelbrot"
# define MANDELBROT_NUM 1
# define JULIA "julia"
# define JULIA_NUM 2

# define WIN_SIZE 540

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
    u_int32_t color;
    int max_iterations;
}   t_fractal;

typedef struct s_engine
{
    void        *mlx;
	void        *window;
    t_image     image;
    t_fractal   fractal;
}   t_engine;

void calculate_mandelbrot(t_engine *engine, t_fractal *fract, t_pixel *pixel);

#endif  /* FRACTAL_H */
