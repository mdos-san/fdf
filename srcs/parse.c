/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:07:39 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 12:29:08 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	parse(t_par *par)
{
	int		fd;
	char	*line;
	char	**data;

	fd = open(par->file, O_RDONLY);
	line = NULL;
	data = NULL;
	ft_putendl("=============  MAP  =============");
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		data = ft_strsplit(line, ' ');
		while (data[i])
		{


		}
		++par->size_y;
	}
	ft_putendl("============= INFO. =============");
	ft_putstr("size_y = ");
	ft_putnbrl(par->size_y);
	close(fd);
	return (1);
}
