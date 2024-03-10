#include <stdio.h>
#include "utils.h"

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

void    ft_strlower(char *str)
{
    int i;
    
    if (!str)
        return ;
    i = -1;
    while (str[++i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= 32;
    }
}

void    show_help()
{
    ft_putstr_fd("\n", 1);
    ft_putstr_fd(" +------------------ Let me help you! ----------------------+\n", 1);
    ft_putstr_fd(" |                                                          |\n", 1);
    ft_putstr_fd(" | Usage: ./fractol [mandelbrot / julia / burning_ship]     |\n", 1);
    ft_putstr_fd(" | e.g: ./fractol mandelbrot                                |\n", 1);
    ft_putstr_fd(" |                                                          |\n", 1);
    ft_putstr_fd(" |----------------------- KEYBOARD -------------------------|\n", 1);
    ft_putstr_fd(" |                                                          |\n", 1);
    ft_putstr_fd(" | Press ESC to close the window                            |\n", 1);
    ft_putstr_fd(" | Press one of [1-5] to move to another fractal            |\n", 1);
    ft_putstr_fd(" | Press one of [Q-Y] keys to change the color of fractal   |\n", 1);
    ft_putstr_fd(" | Press one of [A-H] keys to change the color of fractal   |\n", 1);
    ft_putstr_fd(" | Use mouse scroll to zoom in and out of the fractal       |\n", 1);
    ft_putstr_fd(" | Press the arrow keys to change the viewpoint             |\n", 1);
    ft_putstr_fd(" | Press L to lock Julia's fractal                          |\n", 1);
    ft_putstr_fd(" | Press Zero to reset the fractal                          |\n", 1);
    ft_putstr_fd(" +----------------------------------------------------------+\n", 1);
    ft_putstr_fd("\n", 1);
    exit(EXIT_SUCCESS);
}
