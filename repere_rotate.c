#include "fdf.h"

void	repere_rotate_x(t_vec *v1, t_vec *v2, t_vec *v3, double angle)
{
	vec_rotate_x(v1, angle);
	vec_rotate_x(v2, angle);
	vec_rotate_x(v3, angle);
}

void	repere_rotate_y(t_vec *v1, t_vec *v2, t_vec *v3, double angle)
{
	vec_rotate_y(v1, angle);
	vec_rotate_y(v2, angle);
	vec_rotate_y(v3, angle);
}

void	repere_rotate_z(t_vec *v1, t_vec *v2, t_vec *v3, double angle)
{
	vec_rotate_z(v1, angle);
	vec_rotate_z(v2, angle);
	vec_rotate_z(v3, angle);
}
