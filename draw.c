#include "fdf.h"

void draw_case_one(t_env *e)
{
	int x;

	x = 0;
	int x1 = 30;
	int y1 = 250;
	int x2 = 60;
	int y2 = 300;

	x = x1;
	while (x <= x2)
	{
		pxl_to_image(e, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), 0xFF0000);
		x++;
	}
}

/*
void draw_line(t_env *e, int x1, int y1, int x2, int y2)
{

}
*/
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
