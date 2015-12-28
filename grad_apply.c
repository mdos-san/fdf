/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:17:06 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 12:22:43 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grad_apply(t_pnt *pnt, t_grad grad)
{
	*((unsigned char*)&pnt->color + 0) += grad.b;
	*((unsigned char*)&pnt->color + 1) += grad.g;
	*((unsigned char*)&pnt->color + 2) += grad.r;
};
