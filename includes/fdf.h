/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 18:14:22 by mdos-san         ###   ########.fr       */
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
# define KeyPress 2
# define KeyPressMask (1L<<0)
# define KeyRelease 3
# define KeyReleaseMask (1L<<1)
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
	double	r;
	double	g;
	double	b;
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

typedef struct		s_even
{
	int	coef_add;
}					t_even;

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
	t_pnt	a;
	t_pnt	b;
	t_pnt	**pnt;
	int		nb_pnt;
	double	coef;
	unsigned int	color1;
	unsigned int	color2;
	int				coef_add;
	t_vec			*vx;
	t_vec			*vy;
	t_vec			*vz;
	char			event_change_color;
	char			event_zoom;
	char			event_height;
}					t_par;

t_chain	*chain_new(void);
int		chain_max(t_chain *chain);
int		chain_min(t_chain *chain);
void	start_rendering(t_par *par);
void	img_put_pixel(t_par *par, t_pnt pnt, int color);
void	img_clear(t_par *par);
t_pnt	*pnt_new(double x, double y, double z, unsigned int color);
void	pnt_init(t_pnt *pnt, double x, double y, double z);
void	pnt_translate(t_pnt *pnt, t_vec vec, int nb, int neg);
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
t_grad			*grad_new(double r, double g, double b);
t_grad			*get_grad(unsigned int *color1, unsigned int *color2, int size);
void			grad_apply(t_pnt *pnt, t_grad grad, double coef);
void	key_event(t_par *par);
void	expose_event(t_par *par);
int		expose_hook(t_par *par);
t_vec	*vec_new(double x, double y, double z);
void	vec_del(t_vec **a_vec);
void	vec_draw(t_par *par, t_vec *vec, unsigned int color);
void	vec_rotate_x(t_vec *vec, double angle);
void	vec_rotate_y(t_vec *vec, double angle);
void	vec_rotate_z(t_vec *vec, double angle);
void	vec_multiply(t_vec *vec, double coef);
void	vec_add(t_vec *vec, double valeur);
void	repere_rotate_x(t_vec *v1, t_vec *v2, t_vec *v3, double angle);
void	repere_rotate_y(t_vec *v1, t_vec *v2, t_vec *v3, double angle);
void	repere_rotate_z(t_vec *v1, t_vec *v2, t_vec *v3, double angle);

#endif
