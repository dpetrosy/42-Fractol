#ifndef EVENTS_H
# define EVENTS_H

# include "fractal.h"

int on_render_frame_event(t_engine *engine);
int	on_destroy_event(t_engine *engine);
int on_key_hook_event(int key, t_engine *engine);

#endif  /* EVENTS_H */
