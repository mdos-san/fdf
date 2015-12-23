/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:23:09 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/23 16:45:05 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_add(unsigned int *a, unsigned int *b)
{
	*((unsigned char*)a + 0) += *((unsigned char*)b + 0);
	*((unsigned char*)a + 1) += *((unsigned char*)b + 1);
	*((unsigned char*)a + 2) += *((unsigned char*)b + 2);
	*((unsigned char*)a + 3) += *((unsigned char*)b + 3);
}
