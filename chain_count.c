/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:17:06 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/16 16:23:23 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	chain_count(t_chain *chain)
{
	int		i;
	t_chain	*cursor;

	i = 0;
	cursor = chain;
	if (!chain)
		return (0);
	while (cursor->next)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}
