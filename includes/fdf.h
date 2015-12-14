/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/14 23:53:20 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <stdlib.h>

typedef struct		s_chain
{
	char			**pos;
	int				*tab;
	int				size;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

t_chain	*chain_new(void);
void	chain_add(t_chain *chain);
t_chain	*parse_file(int fd);
void	assign_pos(t_chain *chain);

#endif
