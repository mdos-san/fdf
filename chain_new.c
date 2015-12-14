#include <stdlib.h>
#include "fdf.h"

t_chain	*chain_new(void)
{
	t_chain	*new;

	new = (t_chain*)malloc(sizeof(t_chain));
	new->pos = 0;
	new->tab = 0;
	new->next = 0;
	return (new);
}
