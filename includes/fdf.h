/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 17:28:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 600
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

typedef struct		s_chain
{
	char			**pos;
	int				*tab;
	int				size;
	struct s_chain	*next;
}					t_chain;

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

typedef struct		s_par
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		ed;
}					t_par;

t_chain	*chain_new(void);
void	chain_add(t_chain *chain);
int		chain_count(t_chain *chain);
t_chain	*parse_file(int fd);
void	assign_pos(t_chain *chain);
void	start_rendering(void);
t_img	*img_new(void *mlx, int	width, int height);
void	img_put_pixel(t_par *par, int x, int y, int color);
void	draw_test(void *mlx, t_chain *chain, t_pnt *o, t_img *img);

#endif
