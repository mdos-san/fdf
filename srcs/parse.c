/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:07:39 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 12:47:39 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	parse(t_par *par)
{
	int		fd;
	char	*line;
	char	**data;
	int		i;

	fd = open(par->file, O_RDONLY);
	line = NULL;
	data = NULL;
	i = 0;
	ft_putendl("=============  MAP  =============");
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		data = ft_strsplit(line, ' ');
		while (data[i])
		{
			
			i++;
		}
		i = 0;
		++par->size_y;
	}
	ft_putendl("============= INFO. =============");
	ft_putstr("size_y = ");
	ft_putnbrl(par->size_y);
	close(fd);
	return (1);
}
