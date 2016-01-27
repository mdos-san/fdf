#include "fdf.h"

t_color	*color_new(char r, char g, char b)
{
	t_color	*new;

	if(!(new = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	new->r = r;
	new->g = g;
	new->b = b;
	new->a = 0;
	return (new);
}
