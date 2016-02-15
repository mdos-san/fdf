/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:19 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/15 07:46:32 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fdf.h"

int	main(int ac, char **av)
{
	t_par	*par;

	if (ac != 2 && ac != 5 && ac != 8)
	{
		ft_putendl("Usage : ./fdf map [r g b] [r g b]");
		return (0);
	}
	if (!(par = (t_par*)malloc(sizeof(t_par))))
		return (0);
	par->color1 = (ac != 5 && ac != 8) ? color_get(255, 255, 255, 0) :
				color_get(ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), 0);
	par->color2 = (ac != 8) ? color_get(255, 255, 255, 0) :
				color_get(ft_atoi(av[5]), ft_atoi(av[6]), ft_atoi(av[7]), 0);
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
