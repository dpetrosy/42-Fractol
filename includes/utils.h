#ifndef UTILS_H
# define UTILS_H

#include "fractal.h"

void    error_message(char *text, int mode);
void    show_help();
char    *get_fractal_type(char *str);
void    init_engine(t_engine *engine, char *arg);

#endif  /* UTILS_H */