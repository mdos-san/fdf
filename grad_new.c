/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:42:53 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 11:46:07 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grad	*grad_new(int r, int g, int b)
{
	t_grad	*new;

	if(!(new = (t_grad*)malloc(sizeof(t_grad))))
		return (NULL);
	new->r = r;
	new->g = g;
	new->b = b;
	return (new);
}
