/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:55:36 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 11:55:41 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grad	*get_grad(unsigned int *color1, unsigned int *color2, int size)
{
	int		r;
	int		g;
	int		b;
	t_grad	*grad;

	b = *((unsigned char*)color1 + 0) - *((unsigned char*)color2 + 0) / size;
	g = *((unsigned char*)color1 + 1) - *((unsigned char*)color2 + 1) / size;
	r = *((unsigned char*)color1 + 2) - *((unsigned char*)color2 + 2) / size;
	grad = grad_new(r, g, b);
	return (grad);
}
