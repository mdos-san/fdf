#include "fdf.h"

void	vec_add(t_vec *vec, double valeur)
{
	vec->x = vec->x + valeur;
	vec->y = vec->y + valeur;
	vec->z = vec->z + valeur;
}
