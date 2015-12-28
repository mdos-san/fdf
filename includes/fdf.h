/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 13:06:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 600
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define LEN 10

typedef struct		s_pnt
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}					t_pnt;

typedef struct		s_grad
{
	int	r;
	int	g;
	int	b;
}					t_grad;

typedef struct		s_vec
{
	double	x;
	double	y;
	double	z;
}					t_vec;

typedef struct		s_chain
{
	t_pnt			*pnt;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_par
{
	int		fd;
	char	*file;
	t_chain	*chain;
	int		size_x;
	int		size_y;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		ed;
	t_pnt	o;
	t_pnt	**pnt;
	int		nb_pnt;
	int		coef;
	unsigned int	*color;
}					t_par;

t_chain	*chain_new(void);
int		chain_max(t_chain *chain);
int		chain_min(t_chain *chain);
void	start_rendering(t_par *par);
void	img_put_pixel(t_par *par, t_pnt pnt, int color);
void	img_clear(t_par *par);
t_pnt	*pnt_new(double x, double y, double z, unsigned int color);
void	pnt_init(t_pnt *pnt, double x, double y, double z);
void	draw(t_par *par);
void	get_pnt(t_par *par, unsigned int color1, unsigned int color2);
void	get_pnt_color(t_par *par, unsigned int color1, unsigned int color2);
void	rotate_x(t_pnt *pnt, double angle);
void	rotate_y(t_pnt *pnt, double angle);
void	rotate_z(t_pnt *pnt, double angle);
void	img_putline(t_par *par, t_pnt a, t_pnt b);
void	move_position(t_par *par, int x, int y);
unsigned int	*color_new(void);
void			color_init(unsigned int *color, int value);
void	color_add(unsigned int *a, unsigned int *b);
t_grad			*grad_new(int r, int g, int b);
t_grad			*get_grad(unsigned int *color1, unsigned int *color2, int size);
void			grad_apply(t_pnt *pnt, t_grad grad);

#endif
