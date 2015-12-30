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

void	pnt_translate(t_pnt *pnt, t_vec vec, int nb, int neg)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (!neg)
		{
			pnt->x += vec.x;
			pnt->y += vec.y;
			pnt->z += vec.z;
		}
		else
		{
			pnt->x -= vec.x;
			pnt->y -= vec.y;
			pnt->z -= vec.z;
		}
		i++;
	}
}
