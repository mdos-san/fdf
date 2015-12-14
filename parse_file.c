/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:29 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/14 16:23:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_x(char *line)
{
	int	i;
	int nb;

	i = 0;
	nb = 0;
	while (line[i] != 0)
	{
		if (line[i] ==  ' ')
			nb++;
		i++;
	}
	return (nb++);
}

int	**parse_file(int fd)
{
	char	*line;
	t_lst	*lst_ln;

	get_next_line(fd, &line);
	t_lst = ft_lstnew();

}
