/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:16:32 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:17:50 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	*color_new(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	*new;

	if (!(new = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	new->r = r;
	new->g = g;
	new->b = b;
	new->a = 0;
	return (new);
}
