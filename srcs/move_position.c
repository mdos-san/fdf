/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 09:46:17 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 14:37:03 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_position(t_par *par, int x, int y)
{
	t_chain	*cur;

	cur = par->chain;
	while (cur)
	{
		cur->pnt->x += x;
		cur->pnt->y += y;
		cur = cur->next;
	}
}
