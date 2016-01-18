/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:07:28 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 18:17:46 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ajust(t_par *par)
{
	t_chain	*cur;

	cur = par->chain;
	while (cur->next)
	{
		cur->pnt->x += par->rep->origin.x - par->size_x / 2;
		cur->pnt->y += par->rep->origin.y - par->size_y / 2;
		cur = cur->next;
	}
}

void	get_pnt(t_par *par, unsigned int color1, unsigned int color2)
{
	char	*line;
	char	**tab;
	t_chain	*tmp;
	t_chain	*cur;
	int		i;
	int		y;

	i = 0;
	y = 0;
	tab = 0;
	line = 0;
	par->chain = chain_new();
	cur = par->chain;
	par->fd = open(par->file, O_RDONLY);
	while (get_next_line(par->fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		while (tab[i])
		{
			cur->pnt->x = i;
			cur->pnt->y = y;
			cur->pnt->z = ft_atoi(tab[i]) * par->coef;
			cur->pnt->color = color1;
			tmp = chain_new();
			cur->next = tmp;
			cur = cur->next;
			i++;
		}
		par->size_x = i;
		i = 0;
		y++;
	}
	par->size_y = y;
	get_pnt_color(par, color1, color2);
	ajust(par);
	close(par->fd);
}
