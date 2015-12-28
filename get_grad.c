/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:55:36 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 13:01:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grad	*get_grad(unsigned int *color1, unsigned int *color2, int size)
{
	int		r;
	int		g;
	int		b;
	t_grad	*grad;

	b = (int)(*((unsigned char*)color2 + 0) - *((unsigned char*)color1 + 0));
	g = (int)(*((unsigned char*)color2 + 1) - *((unsigned char*)color1 + 1));
	r = (int)(*((unsigned char*)color2 + 2) - *((unsigned char*)color1 + 2));
	if (size != 0)
	{
		b /= size;
		g /= size;
		r /= size;
	}
	else
	{
		b = 0;
		g = 0;
		r = 0;
	}
	grad = grad_new(r, g, b);
	return (grad);
}
