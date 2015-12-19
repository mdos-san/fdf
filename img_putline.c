#include "fdf.h"

void	img_putline(t_par *par, t_pnt a, t_pnt b)
{
	double	coef;
	double	p;

	coef = (b.y - a.y) / (b.x - a.x);
	p = a.y - (coef * a.x);
	while ((int)a.x != (int)b.x)
	{
		a.y = a.x * coef + p;
		img_put_pixel(par, a, WHITE);
		if (a.x < b.x)
			a.x++;
		else
			a.x--;
	}
}
