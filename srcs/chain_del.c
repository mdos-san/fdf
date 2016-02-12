/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:15:46 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:15:47 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
