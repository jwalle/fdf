/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 11:14:55 by jwalle            #+#    #+#             */
/*   Updated: 2015/04/20 11:38:13 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
char *get_map(char *map)
{
	int fd;
	char *temp;
	
	fd = open("test_maps/42.fdf", O_RDONLY);
	temp = malloc(10000);
	get_next_line(fd, &map);
	printf("%s\n", map);

	while (get_next_line(fd, &temp) == 1)
	{
		ft_strjoin(map, temp);
		printf("%s\n", map);
	}
	return (map);
}
*/


void	pxl_to_image(t_env *e, int x, int y, uint32_t color)
{
	int pixel;

	pixel = (x * e->sl) + (y *(e->bpp / 8));
	memcpy(e->data + pixel, &color, e->bpp / 8);
}

void draw(t_env *e)
{
	int x;
	int y;

	x = 100;
	while (x < 200)
	{
		y = 100;
		while (y < 200)
		{
			pxl_to_image(e, x, y, 0xFF0000);
			//mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);

}

int main()
{
	//char *map;
	//map = malloc(100000);
	//get_map(map);
	//printf("%s\n", map);
	t_env e;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

// http://perso.epitech.eu/~ol/work/raytracer/cours/cours/
