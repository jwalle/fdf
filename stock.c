#include "fdf.h"

t_coord	*get_position(int x, int y, int z, t_env *e)
{
	t_coord 	*new;
	//double	temp;

	new = (t_coord*)malloc(sizeof(t_coord));
	//printf("malloc = t_coord\n");
	new->x = (x + 1);
	new->y = y;
	new->z = z;

	new->x = ((new->x * e->zoom) + (new->y * e->zoom) + e->start_y);
	//new->x = ((x + 1) * e->zoom) + (y * e->zoom) + e->start_y;
	new->y = ((e->h / 0.5) * (new->y * e->zoom) + e->start_x);
	//new->y = ((e->h / 0.5) * (y * e->zoom) + e->start_x);
	new->y *= e->g;
	//temp = new->x;
	//new->x = (e->g * new->x) - (e->w * new->y);
	//new->y = (e->z * new->z) + ((e->g / 2) * temp) + ((e->w / 2) * new->y);
	new->x = new->x + (e->z * new->z);
	new->y = new->y + ((e->z / 2) * new->z);
	
	return (new);
}
