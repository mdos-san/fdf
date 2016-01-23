#include "fdf.h"

void	chain_zoom(t_chain *chain, double zoom, t_rep rep)
{
	t_chain	*cur;

	cur = chain;
	while (cur)
	{
		cur->pnt->x -= rep.origin.x;
		cur->pnt->y -= rep.origin.y;
		cur->pnt->z -= rep.origin.z;
		cur->pnt->x *= zoom;
		cur->pnt->y *= zoom;
		cur->pnt->z *= zoom;
		cur->pnt->x += rep.origin.x;
		cur->pnt->y += rep.origin.y;
		cur->pnt->z += rep.origin.z;
		cur = cur->next;
	}
}
