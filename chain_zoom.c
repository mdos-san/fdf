#include "fdf.h"

void	chain_zoom(t_chain *chain, double zoom)
{
	t_chain	*cur;

	cur = chain;
	while (cur->next)
	{
		cur->pnt->x *= zoom;
		cur->pnt->y *= zoom;
		cur->pnt->z *= zoom;
		cur = cur->next;
	}
}
