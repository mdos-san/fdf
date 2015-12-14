#include "fdf.h"

void	chain_add(t_chain *chain)
{
	t_chain	*new;

	new = chain_new();
	chain->next = new;
}
