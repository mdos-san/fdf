/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:07:39 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 14:52:52 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ajust(t_par *par)
{
	t_chain	*cur;

	cur = par->chain;
	while (cur)
	{
		cur->pnt->x += par->rep->origin.x - ((double)par->size_x - 1) / 2;
		cur->pnt->y += par->rep->origin.y - ((double)par->size_y - 1) / 2;
		cur = cur->next;
	}
}

int	parse(t_par *par)
{
	int		fd;
	int		i;
	int		ret;
	char	*line;
	char	**data;
	t_chain	*cur;
	t_chain	*tmp;

	fd = open(par->file, O_RDONLY);
	i = 0;
	line = NULL;
	data = NULL;
	cur = NULL;
	tmp = NULL;
	par->size_x = 0;
	par->size_y = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (-1);
		data = ft_strsplit(line, ' ');
		while (data[i])
		{
			cur = chain_new();
			cur->pnt->x = i;
			cur->pnt->y = par->size_y;
			cur->pnt->z = ft_atoi(data[i]) * par->coef;
			cur->pnt->color = par->color1;
			if (tmp != NULL)
				tmp->next = cur;
			else
				par->chain = cur;
			tmp = cur;
			++i;
		}
		if (par->size_y == 0)
			par->size_x = i;
		else
		{
			if (par->size_x != i)
			{
				ft_putendl("Error in file, please check if all line have the same length.");
				return (-1);
			}
		}
		i = 0;
		++par->size_y;
	}
	ajust(par);
	get_pnt_color(par);
	par->angle_z = 45;
	par->angle_x = 45;
	draw(par);
	par->angle_z = 0;
	par->angle_x = 0;
	close(fd);
	return (1);
}
