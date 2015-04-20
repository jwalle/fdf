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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minilibx_macos/mlx.h"
#include "fdf.h"
#include "get_next_line.h"

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

void draw(void *mlx, void *win)
{
	int x;
	int y;

	x = 100;
	while (x < 200)
	{
		y = 100;
		while (y < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

int expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	mlx_pixel_put(e->mlx, e->win, 2, 2, 0xFF0000);
	printf("key : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int main()
{
	//char *map;
	t_env e;

	//map = malloc(100000);
	//get_map(map);
	//printf("%s\n", map);

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
