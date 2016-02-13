/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:07:39 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/13 07:37:59 by mdos-san         ###   ########.fr       */
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
	get_pnt_color(par);
	par->angle_z = 45;
	par->angle_x = 45;
	draw(par);
	par->angle_z = 0;
	par->angle_x = 0;
	close(par->fd);
}

static void	assign_pnt(t_par *par, t_chain **cur, t_chain **tmp, char **data)
{
	*cur = chain_new();
	(*cur)->pnt->x = par->i;
	(*cur)->pnt->y = par->size_y;
	(*cur)->pnt->z = ft_atoi(data[par->i]) * par->coef;
	(*cur)->pnt->color = par->color1;
	if (*tmp != NULL)
		(*tmp)->next = *cur;
	else
		par->chain = *cur;
	*tmp = *cur;
	++par->i;
}

static void	free_var(t_par *par, char ***data, char **line)
{
	par->i = 0;
	++par->size_y;
	while ((*data)[par->i])
	{
		free((*data)[par->i]);
		(*data)[par->i] = NULL;
		++par->i;
	}
	par->i = 0;
	(*data != NULL) ? free(*data) : 0;
	(*line != NULL) ? free(*line) : 0;
}

int			parse(t_par *par)
{
	int		ret;
	char	*line;
	char	**data;
	t_chain	*cur;
	t_chain	*tmp;

	par->fd = open(par->file, O_RDWR);
	(par->fd == -1) ? fdf_error(par, "Can't open the file.") : 0;
	tmp = NULL;
	par->size_y = 0;
	par->size_x = 0;
	while ((ret = get_next_line(par->fd, &line)))
	{
		(ret == -1) ? fdf_error(par, "Gnl is getting an error.") : 0;
		data = ft_strsplit(line, ' ');
		while (data[par->i])
			assign_pnt(par, &cur, &tmp, data);
		if (par->size_y == 0)
			par->size_x = par->i;
		else
			(par->size_x != par->i) ? fdf_error(par, "File is invalid.") : 0;
		free_var(par, &data, &line);
	}
	ajust(par);
	return (1);
}
