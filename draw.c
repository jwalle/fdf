#include "fdf.h"

void draw_line(t_env *e, int x1, int y1, int x2, int y2)
{
	
}

void draw(t_env *e)
{
	int x;
	int y;

	draw_line(e, 200 );
	x = 100;
	while (x < 200)
	{
		y = 100;
		while (y < 200)
		{
			pxl_to_image(e, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
