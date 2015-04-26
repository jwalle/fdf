#include "fdf.h"

int		absolute(int res)
{
	if (res < 0)
		res *= (-1);
	return (res);
}

uint32_t	ft_get_color(int z)
{
	uint32_t color;

	if (z < 0)
		color = 0xFFA500;
	if (z == 0)
		color = 0xFFFFFF;
	if (z > 0 && z < 10)
		color = 0x0000FF;
	if (z >= 10)
		color = 0xFF0000;
	return (color);

}

void draw_case_one(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->x;
	while (x <= dest->x && x < WINDOW_SIZE_X)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) / (dest->x - ori->x), ft_get_color(dest->z));
		x++;
	}
}

void draw_case_two(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->x;
	while (x <= ori->x && x < WINDOW_SIZE_X)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) / (dest->x - ori->x),	ft_get_color(dest->z));
		x++;
	}
}

void draw_case_three(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->y;
	while (x <= dest->y && x < WINDOW_SIZE_X)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e,ori->x + ((dest->x - ori->x) * (x - ori->y)) / (dest->y - ori->y), x, ft_get_color(dest->z));
		x++;
	}
}

void draw_case_four(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->y;
	while (x <= ori->y && x < WINDOW_SIZE_X)
	{
		//printf("ori->x = %d, ori->y = %d, dest->x = %d, dest->y = %d\n", ori->x, ori->y, dest->x, dest->y);
		pxl_to_image(e, ori->x + ((dest->x - ori->x) * (x - ori->y)) / (dest->y - ori->y), x, ft_get_color(dest->z));
		x++;
	}
}

void	set_coord(t_coord *ori, t_coord* dest_r, t_coord *dest_d, t_env *e)
{
		//ori->x = (e->start_x + (e->zoom * ori->x) - (20 * ori->x));

		ori->x = (ori->x * e->zoom) + (ori->y * e->zoom) + e->start_y;
		ori->x /= e->w;
		ori->y = ((e->h / 2.0) * (ori->y * e->zoom) + e->start_x);
		ori->y *= e->g;
		ori->x = ori->x + (e->z * ori->z);
		ori->y = ori->y + ((e->z / 2) * ori->z);
		
		//ori->y = (e->start_y + (e->zoom * ori->y) + (10 * ori->y));
		//printf("plop2, 	ori x = %d, ori y = %d\n", ori->x, ori->y);
		//printf("ori_z = %d\n", ori->z);
		//ori->y -= e->h * ori->z;

		//dest_r->x = (e->start_x + (e->zoom * dest_r->x) - (20 * dest_r->x));
		dest_r->x = (dest_r->x * e->zoom) + (dest_r->y * e->zoom) + e->start_y;
		dest_r->x /= e->w;
		dest_r->y = ((e->h / 2.0) * (dest_r->y * e->zoom) + e->start_x);
		dest_r->y *= e->g;
		dest_r->x = dest_r->x + (e->z * dest_r->z);
		dest_r->y = dest_r->y + ((e->z / 2) * dest_r->z);
		//dest_r->y = (e->start_y + (e->zoom * dest_r->y) + (10 + (dest_r->y * 10)));
		//dest_r->y -= e->h * dest_r->z;
		//printf("dest_r x = %d, dest_r y = %d\n", dest_r->x, dest_r->y);
		select_draw(ori, dest_r, e);

		//dest_d->x = (e->start_x + (e->zoom * dest_d->x) - (20 + (20 * dest_d->x)));
		dest_d->x = (dest_d->x * e->zoom) + (dest_d->y * e->zoom) + e->start_y;
		dest_d->x /= e->w;
		dest_d->y = ((e->h / 2.0) * (dest_d->y * e->zoom) + e->start_x);
		dest_d->y *= e->g;
		dest_d->x = dest_d->x + (e->z * dest_d->z);
		dest_d->y = dest_d->y + ((e->z / 2) * dest_d->z);
		//dest_d->y = (e->start_y + (e->zoom * dest_d->y) + (10 * dest_d->y));
		//dest_d->y -= e->h * dest_d->z;
		//printf("dest_d x = %d, dest_d y = %d\n", dest_d->x, dest_d->y);
		select_draw(ori, dest_d, e);

}

void	select_draw(t_coord *ori, t_coord* dest, t_env *e)
{
	if ((absolute(dest->x - ori->x)) >= (absolute(dest->y - ori->y)))
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
	while (all != NULL)
	{
		set_coord(all->origin, all->right, all->down, e);
		//select_draw(all->origin, all->right, e);
		//select_draw(all->origin, all->down, e);
		all = all->next;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
