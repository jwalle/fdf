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
		color = 0x71ABD8;
	if (z == 0)
		color = 0xF5F4F2;
	if (z > 0 && z <= 5)
		color = 0xACD0A5;
	if (z > 5 && z <= 10)
		color = 0xA8C68F;
	if (z > 10 && z <= 15)
		color = 0xEFEBC0;
	if (z > 15 && z <= 20)
		color = 0xCAB982;
	if (z > 20 && z <= 25)
		color = 0xAA8753;
	if (z > 25)
		color = 0xCAC3B8;
	return (color);
}

void draw_case_one(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->x;
	while (x <= dest->x && x < WINDOW_SIZE_X)
	{
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
		pxl_to_image(e, ori->x + ((dest->x - ori->x) * (x - ori->y)) / (dest->y - ori->y), x, ft_get_color(dest->z));
		x++;
	}
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
		if (all->right != NULL)
			select_draw(all->origin, all->right, e);
		if (all->down != NULL)
			select_draw(all->origin, all->down, e);
		all = all->next;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	free(all);
}
