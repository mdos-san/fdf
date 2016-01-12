/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:55:36 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 14:17:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grad	*get_grad(unsigned int *color1, unsigned int *color2, int size)
{
	double		r;
	double		g;
	double		b;
	t_grad	*grad;

	b = (double)(*((unsigned char*)color2 + 0) - *((unsigned char*)color1 + 0));
	g = (double)(*((unsigned char*)color2 + 1) - *((unsigned char*)color1 + 1));
	r = (double)(*((unsigned char*)color2 + 2) - *((unsigned char*)color1 + 2));
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
