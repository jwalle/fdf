#include "fdf.h"

int		absolute(int res)
{
	if (res < 0)
		res *= (-1);
	return (res);
}

void draw_case_one(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->x ;
	while (x <= dest->x)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) / (dest->x - ori->x), 0xFF0000);
		x++;
	}
}

void draw_case_two(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->x ;
	while (x <= ori->x)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) / (dest->x - ori->x), 0xFF0000);
		x++;
	}
}

void draw_case_three(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->y ;
	while (x <= dest->y)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e, x, ori->x + ((dest->x - ori->x) * (x - ori->y)) / (dest->y - ori->y), 0xFF0000);
		x++;
	}
}

void draw_case_four(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->y ;
	while (x <= ori->y)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e, x, ori->x + ((dest->x - ori->x) * (x - ori->y)) / (dest->y - ori->y), 0xFF0000);
		x++;
	}
}

void	set_coord(t_coord *ori, t_coord* dest_r, t_coord *dest_d, t_env *e)
{
		ori->x = (e->start_x + (e->zoom * ori->x) - 10) / 1;
		ori->y = (e->start_y + (e->zoom * ori->y) + 10) / 1;
		ori->y -= e->h * ori->z;

	if (dest_r->x && dest_r->y)
	{
		dest_r->x = (e->start_x + (e->zoom * dest_r->x) - 10) / 1;
		dest_r->y = (e->start_y + (e->zoom * dest_r->y) + 10) / 1;
		dest_r->y -= e->h * dest_r->z;
		select_draw(ori, dest_r, e);
	}
	if (dest_d->x != 0 && dest_d->y != 0)
	{
		dest_d->x = (e->start_x + (e->zoom * dest_d->x) - 10) / 1;
		dest_d->y = (e->start_y + (e->zoom * dest_d->y) + 10) / 1;
		dest_d->y -= e->h * dest_d->z;
		select_draw(ori, dest_d, e);
	}
	printf("plop\n");
}

void	select_draw(t_coord *ori, t_coord* dest, t_env *e)
{
	if ((absolute(ori->x - dest->x)) >= (absolute(dest->y - ori->y)))
	{
		if(ori->x < dest->x)
			draw_case_one(e, ori, dest);
		else
			draw_case_two(e, ori, dest);
	}
	else
	{
		if (ori->y < dest->y)
			draw_case_three(e, ori, dest);
		else
			draw_case_four(e, ori, dest);
	}
}

void draw(t_env *e)
{
	t_point *all;

	all = ll_stock(e);
	while (all->next != NULL)
	{
		set_coord(all->origin, all->right, all->down, e);
		//select_draw(all->origin, all->right, e);
		//select_draw(all->origin, all->down, e);
		//set_coord(all->origin, all->down, e);

		all = all->next;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
