#include "fdf.h"

void	chain_del(t_chain **addr)
{
	t_chain	*cur;
	t_chain	*tmp;

	cur = *addr;
	while (cur)
	{
		tmp = cur->next;
		if (cur->pnt)
		{
			free(cur->pnt);
			cur->pnt = NULL;
		}
		cur->next = NULL;
		free(cur);
		cur = tmp;
	}
	cur = NULL;
}
