/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:19 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 12:25:01 by mdos-san         ###   ########.fr       */
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
	par->coef = 1;
	par->file = av[1];
	par->size_y = 0;
	parse(par);
//	start_rendering(par);
	return (0);
}
