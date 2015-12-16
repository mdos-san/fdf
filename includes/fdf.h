/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/16 18:12:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 600

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

typedef struct		s_img
{
	void	*img;
	int		width;
	int		height;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}					t_img;

typedef struct		s_pnt
{
	int	x;
	int	y;
}					t_pnt;

typedef struct		s_vec
{
	int	x;
	int	y;
}					t_vec;

t_chain	*chain_new(void);
void	chain_add(t_chain *chain);
int		chain_count(t_chain *chain);
t_chain	*parse_file(int fd);
void	assign_pos(t_chain *chain);
void	start_rendering(t_chain *chain);
t_img	*img_new(void *mlx, int	width, int height);
void	img_put_pixel(void *mlx, t_img *img, t_pnt *pnt, unsigned int color);

#endif
