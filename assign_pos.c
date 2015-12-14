#include "libft.h"
#include "fdf.h"

static int	count_tab(char	**dbl_tab)
{
	int	i;

	i = 0;
	while (dbl_tab[i])
		i++;
	return (i + 1);
}

void	assign_pos(t_chain	*chain)
{
	int		i;
	int		len;
	t_chain	*cursor;

	i = 0;
	len = 0;
	cursor = chain;
	while (cursor->pos)
	{
		len = count_tab(cursor->pos);
		cursor->tab = (int*)malloc(sizeof(int) * (len + 1));
		cursor->size = len;
		while(i < len)
		{
			cursor->tab[i] = ft_atoi(cursor->pos[i]);
			i++;
		}
		cursor = cursor->next;
		i = 0;
	}
}
