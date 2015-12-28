/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:17:06 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 15:03:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grad_apply(t_pnt *pnt, t_grad grad, double coef)
{
	*((unsigned char*)&pnt->color + 0) += (unsigned char)(grad.b * coef);
	*((unsigned char*)&pnt->color + 1) += (unsigned char)(grad.g * coef);
	*((unsigned char*)&pnt->color + 2) += (unsigned char)(grad.r * coef);
};
