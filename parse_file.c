/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:39:29 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/14 23:51:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_chain		*parse_file(int fd)
{
	char	*line;
	t_chain	*chain;
	t_chain	*cursor;

	line = 0;
	chain = chain_new();
	cursor = chain;
	while(get_next_line(fd, &line))
	{
		cursor->pos = ft_strsplit(line, ' ');
		chain_add(cursor);
		cursor = cursor->next;
	}
	return (chain);
}
