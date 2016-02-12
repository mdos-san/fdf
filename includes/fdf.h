/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:24:25 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:48:03 by mdos-san         ###   ########.fr       */
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
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASE 3
# define KEYRELEASEMASK (1L<<1)
# define WIDTH 1920
# define HEIGHT 1080
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define LEN 10

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef struct		s_pnt
{
	double			x;
	double			y;
	double			z;
	t_color			color;
}					t_pnt;

typedef struct		s_grad
{
	double			r;
	double			g;
	double			b;
}					t_grad;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_rep
{
	t_pnt			origin;
	t_vec			vx;
	t_vec			vy;
	t_vec			vz;
}					t_rep;

typedef struct		s_chain
{
	t_pnt			*pnt;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_even
{
	int				coef_add;
}					t_even;

typedef struct		s_par
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				ed;
	int				fd;
	char			*file;
	t_chain			*chain;
	int				size_x;
	int				size_y;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	int				nb_pnt;
	double			coef;
	t_color			color1;
	t_color			color2;
	int				coef_add;
	t_rep			*rep;
	char			event_change_color;
	char			event_zoom;
	char			event_height;
}					t_par;

t_chain				*chain_new(void);
void				chain_del(t_chain **addr);
int					chain_max(t_chain *chain);
int					chain_min(t_chain *chain);
void				chain_zoom(t_chain *chain, double zoom, t_rep rep);
void				start_rendering(t_par *par);
void				img_put_pixel(t_par *par, t_pnt pnt, int color);
void				img_clear(t_par *par);
t_pnt				*pnt_new(double x, double y, double z, t_color color);
t_pnt				pnt_get(double x, double y, double z);
void				pnt_init(t_pnt *pnt, double x, double y, double z);
void				pnt_translate(t_pnt *pnt, t_vec vec, int nb);
void				draw(t_par *par);
void				get_pnt_color(t_par *par);
void				rotate_x(t_pnt *pnt, double angle, t_rep rep);
void				rotate_y(t_pnt *pnt, double angle, t_rep rep);
void				rotate_z(t_pnt *pnt, double angle, t_rep rep);
void				img_putline(t_par *par, t_pnt a, t_pnt b);
t_grad				*grad_new(double r, double g, double b);
t_grad				*get_grad(unsigned int *color1, unsigned int *color2,\
								int size);
void				grad_apply(t_pnt *pnt, t_grad grad, double coef);
void				key_event(t_par *par);
void				expose_event(t_par *par);
int					expose_hook(t_par *par);
t_vec				*vec_new(double x, double y, double z);
void				vec_del(t_vec **a_vec);
t_vec				vec_get(double x, double y, double z);
void				vec_draw(t_par *par, t_vec *vec, t_color color);
void				vec_rotate_x(t_vec *vec, double angle);
void				vec_rotate_y(t_vec *vec, double angle);
void				vec_rotate_z(t_vec *vec, double angle);
void				vec_multiply(t_vec *vec, double coef);
void				vec_add(t_vec *vec, double valeur);
t_rep				*repere_new(t_vec vx, t_vec vy, t_vec vz, t_pnt origin);
void				repere_rotate_x(t_rep *rep, double angle);
void				repere_rotate_y(t_rep *rep, double angle);
void				repere_rotate_z(t_rep *rep, double angle);
int					parse(t_par *par);
t_color				*color_new(unsigned char r, unsigned char g,\
								unsigned char b);
void				color_del(t_color **addr);
void				color_init(t_color *color, unsigned char r,\
						unsigned char g, unsigned char b);
t_color				color_get(unsigned char r, unsigned char b,\
						unsigned char g, unsigned char a);
unsigned int		color_convert(t_color color);
t_color				color_average(t_color a, t_color b);
t_color				color_step(t_color c_a, t_color c_b, int nbr_stp,\
						int act_stp);

#endif
