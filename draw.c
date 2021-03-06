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

	x = ori->x;
	while (x <= dest->x)
	{
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) / (dest->x - ori->x), ft_get_color(dest->z , e));
		x++;
	}
}

void draw_case_two(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->x;
	while (x <= ori->x)
	{
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) / (dest->x - ori->x), ft_get_color(dest->z, e));
		x++;
	}
}

void draw_case_three(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->y;
	while (x <= dest->y)
	{
		pxl_to_image(e,ori->x + ((dest->x - ori->x) * (x - ori->y)) / (dest->y - ori->y), x, ft_get_color(dest->z, e));
		x++;
	}
}

void draw_case_four(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->y;
	while (x <= ori->y)
	{
		pxl_to_image(e, ori->x + ((dest->x - ori->x) * (x - ori->y)) / (dest->y - ori->y), x, ft_get_color(dest->z, e));
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
	//t_point *tmp;

	all = ll_stock(e);
	while (all->origin != NULL)
	{	
		if (all->right != NULL)
			select_draw(all->origin, all->right, e);
		if (all->down != NULL)
			select_draw(all->origin, all->down, e);
		//tmp = all;
		all = all->next;
		//if (tmp->origin != NULL)
		//	free(tmp->origin);
		//if (tmp->right != NULL)
		//	free(tmp->right);
		//if (tmp->down != NULL)
		//	free(tmp->down);
		//tmp = NULL;
		//free(tmp);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	//free_list(all);
}
