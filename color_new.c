/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:46:38 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/23 16:00:30 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	*color_new(void)
{
	unsigned int	*new;

	new = (unsigned int*)malloc(sizeof(unsigned int));
	if (new == 0)
		exit(0);
	*((unsigned char*)new + 0) = 0;
	*((unsigned char*)new + 1) = 0;
	*((unsigned char*)new + 2) = 0;
	*((unsigned char*)new + 3) = 0;
	return (new);
}
