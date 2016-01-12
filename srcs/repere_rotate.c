#include "fdf.h"

void	repere_rotate_x(t_rep *rep, double angle)
{
	vec_rotate_x(&rep->vx, angle);
	vec_rotate_x(&rep->vy, angle);
	vec_rotate_x(&rep->vz, angle);
}

void	repere_rotate_y(t_rep *rep, double angle)
{
	vec_rotate_y(&rep->vx, angle);
	vec_rotate_y(&rep->vy, angle);
	vec_rotate_y(&rep->vz, angle);
}

void	repere_rotate_z(t_rep *rep, double angle)
{
	vec_rotate_z(&rep->vx, angle);
	vec_rotate_z(&rep->vy, angle);
	vec_rotate_z(&rep->vz, angle);
}
