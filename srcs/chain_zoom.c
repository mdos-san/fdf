/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:16:12 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:16:14 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	chain_zoom(t_chain *chain, double zoom, t_rep rep)
{
	t_chain	*cur;

	cur = chain;
	while (cur)
	{
		cur->pnt->x -= rep.origin.x;
		cur->pnt->y -= rep.origin.y;
		cur->pnt->z -= rep.origin.z;
		cur->pnt->x *= zoom;
		cur->pnt->y *= zoom;
		cur->pnt->z *= zoom;
		cur->pnt->x += rep.origin.x;
		cur->pnt->y += rep.origin.y;
		cur->pnt->z += rep.origin.z;
		cur = cur->next;
	}
}
