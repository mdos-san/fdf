#include "fdf.h"

void	color_init(t_color *color, char r, char g, char b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = 0;
}
