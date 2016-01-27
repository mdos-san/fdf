#include "fdf.h"

void	color_init(t_color *color, unsigned char r, unsigned char g, unsigned char b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = 0;
}
