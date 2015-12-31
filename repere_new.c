#include "fdf.h"

t_rep	*repere_new(t_vec vx, t_vec vy, t_vec vz, t_pnt origin)
{
	t_rep	*new;

	new = (t_rep*)malloc(sizeof(t_rep));
	if (!new)
		return (NULL);
	new->vx = vx;
	new->vy = vy;
	new->vz = vz;
	new->origin = origin;
	return (new);
}
