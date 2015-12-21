/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:07:28 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/21 09:28:35 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ajust(t_par *par)
{
	t_chain	*cur;

	cur = par->chain;
	while (cur->next)
	{
		cur->pnt->x = cur->pnt->x * (WIDTH / par->size_x);
		cur->pnt->y = cur->pnt->y * (HEIGHT / par->size_y);
		cur->pnt->x *= 0.9;
		cur->pnt->y *= 0.9;
		cur->pnt->x += 0.05 * WIDTH;
		cur->pnt->y += 0.05 * HEIGHT;
		cur = cur->next;
	}
}

void	get_pnt(t_par *par)
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
	ajust(par);
	close(par->fd);
}
