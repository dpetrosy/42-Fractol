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

# include <stdio.h>
# include "libft.h"
# include "keys.h"
# include "mlx.h"

# define MANDELBROT "mandelbrot"
# define JULIA "julia"

# define WIN_SIZE 700
# define MAX_ITERATIONS 256

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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_image;

typedef struct s_fractal
{
    int zoom;
    int offset_x;
    int offset_y;
    int color;
    char *type;
}   t_fractal;

typedef struct s_engine
{
    void        *mlx;
	void        *window;
    t_image     image;
    t_fractal   fractal;
}   t_engine;

#endif  /* FRACTAL_H */
