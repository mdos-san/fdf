/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:31:23 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 14:36:07 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	chain_max(t_chain *chain)
{
	int	max;
	t_chain	*cur;

	cur = chain;
	max = cur->pnt->z;
	while (cur)
	{
		if (max < cur->pnt->z)
			max = cur->pnt->z;
		cur = cur->next;
	}
	return (max);
}
