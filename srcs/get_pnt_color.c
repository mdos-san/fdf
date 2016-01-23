/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pnt_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:43:50 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 14:36:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pnt_color(t_par *par, unsigned int color1, unsigned int color2)
{
	int		min;
	int		length;
	t_grad	*grad;
	t_chain	*cur;

	cur = par->chain;
	min = chain_min(cur);
	length = chain_max(cur) - chain_min(cur);
	grad = get_grad(&color1, &color2, length);
	while (cur)
	{
		grad_apply(cur->pnt, *grad, cur->pnt->z - min);
		cur = cur->next;
	}
}
