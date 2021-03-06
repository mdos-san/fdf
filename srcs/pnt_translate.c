/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:09:51 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 18:14:08 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pnt_translate(t_pnt *pnt, t_vec vec, int nb)
{
	pnt->x += vec.x * nb;
	pnt->y += vec.y * nb;
	pnt->z += vec.z * nb;
}
