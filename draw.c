#include "fdf.h"

void draw_case_one(t_env *e, t_coord *c)
{
	int x;

	x = c->x1;
	while (x <= c->x2)
	{
		pxl_to_image(e, x, c->y1 + ((c->y2 - c->y1) * (x - c->x1)) / (c->x2 - c->x1), 0xFF0000);
		x++;
	}
}


void draw(t_env *e)
{
	int x;
	int y;

	draw_case_one(e);

	//draw_line(e, 200 );
	x = 100;
	while (x < 200)
	{
		y = 100;
		while (y < 200)
		{
			//pxl_to_image(e, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
