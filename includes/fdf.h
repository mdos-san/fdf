/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 20:26:53 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# define WIDTH 800
# define HEIGHT 600
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define LEN 10

typedef struct		s_chain
{
	char			**pos;
	int				*tab;
	int				size;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_pnt
{
	double	x;
	double	y;
	double	z;
}					t_pnt;

typedef struct		s_vec
{
	double	x;
	double	y;
	double	z;
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
	t_chain	*chain;
	t_pnt	*o;
	t_vec	*vx;
	t_vec	*vy;
	t_vec	*vz;
}					t_par;

t_chain	*chain_new(void);
void	chain_add(t_chain *chain);
int		chain_count(t_chain *chain);
t_chain	*parse_file(int fd);
void	assign_pos(t_chain *chain);
void	start_rendering(t_chain *chain);
void	img_put_pixel(t_par *par, t_pnt pnt, int color);
void	img_clear(t_par *par);
t_vec	*vec_init(double x, double y, double z);
t_pnt	*pnt_init(double x, double y, double z);
void	draw(t_par *par);
void	rotate_x(t_par *par, double angle);

#endif
