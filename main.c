/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:19 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/15 00:31:11 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fdf.h"

int	main(int ac, char **av)
{
	int	fd;
	t_chain	*chain;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	chain = parse_file(fd);
	assign_pos(chain);
	return (0);
}
