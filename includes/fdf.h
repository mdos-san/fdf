/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/16 19:42:13 by mdos-san         ###   ########.fr       */
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

typedef struct		s_expar
{
	t_env	*env;
	t_img	*img;
	t_pnt	*pnt;
	t_chain	*chain;
}					t_expar;

t_chain	*chain_new(void);
void	chain_add(t_chain *chain);
int		chain_count(t_chain *chain);
t_chain	*parse_file(int fd);
void	assign_pos(t_chain *chain);
void	start_rendering(t_chain *chain);
t_img	*img_new(void *mlx, int	width, int height);
void	img_put_pixel(void *mlx, t_img *img, t_pnt *pnt, int color);
void	draw_test(void *mlx, t_chain *chain, t_pnt *o, t_img *img);

#endif
