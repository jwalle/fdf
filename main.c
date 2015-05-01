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

void	pxl_to_image(t_env *e, int x, int y, uint32_t color)
{
	int pixel;

	pixel = 1;
	if (x > 0 && x < WINDOW_SIZE_X && y > 0 && y < WINDOW_SIZE_Y)
	{
		pixel = (x * e->sl) + (y *(e->bpp / 8));
		memcpy(e->data + pixel, &color, e->bpp / 8); //FT_MEMCPY
	}
}

void	ft_init(t_env *e)
{
	e->tab = NULL;
	e->line = 0;
	e->col = 0;
	e->zoom = 12;
	e->h = 1;
	e->start_x = 30;
	e->start_y = 30;
	e->z = -1;
	e->w = 0.5;
	e->g = 0.5;
	e->a = 2;
	e->color_set = 1;
}

int main(int ac, char **av)
{
	t_env e;
	
	ft_init(&e);
	if (ac == 2)
		get_map(&e, av[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

// http://perso.epitech.eu/~ol/work/raytracer/cours/cours/
