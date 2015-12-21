/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:19 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/21 08:03:46 by mdos-san         ###   ########.fr       */
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
	par = (t_par*)malloc(sizeof(t_par));
	par->coef = 1;
	par->file = av[1];
	get_pnt(par);
	start_rendering(par);
	return (0);
}
