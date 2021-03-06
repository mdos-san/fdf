/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:37:03 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 14:36:00 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	chain_min(t_chain *chain)
{
	int		min;
	t_chain	*cur;

	cur = chain;
	min = cur->pnt->z;
	while (cur)
	{
		if (min > cur->pnt->z)
			min = cur->pnt->z;
		cur = cur->next;
	}
	return (min);
}
