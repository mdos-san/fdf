/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:19 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/13 07:04:19 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fdf.h"

int	main(int ac, char **av)
{
	t_par	*par;

	if (ac != 2)
		return (0);
	if (!(par = (t_par*)malloc(sizeof(t_par))))
		return (0);
	par->color1 = color_get(0, 0, 255, 0);
	par->color2 = color_get(0, 255, 0, 0);
	par->coef = 1;
	par->file = av[1];
	par->size_x = 0;
	par->size_y = 0;
	par->i = 0;
	par->chain = NULL;
	par->rep = repere_new(vec_get(1, 0, 0),
							vec_get(0, 1, 0),
							vec_get(0, 0, 1),
							pnt_get(WIDTH / 2, HEIGHT / 2, 0));
	start_rendering(par);
	return (0);
}
