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
		pixel = (x * e->sl) + (y * (e->bpp / 8));
		ft_memcpy(e->data + pixel, &color, e->bpp / 8);
	}
}

void	ft_reset(t_env *e)
{
	e->zoom = 15;
	e->h = 3.5;
	e->start_x = 50;
	e->start_y = 200;
	e->z = -2.5;
	e->w = 0.9;
	e->g = 0.5;
	e->a = 30;
	e->a = 40;
	e->color_set = 1;
	e->projection = 2;
}

void	ft_reset_iso(t_env *e)
{
	e->zoom = 10;
	e->h = -9.3;
	e->start_x = 100;
	e->start_y = 0;
	e->z = 4.5;
	e->w = -2.1;
	e->g = 3;
	e->a = 34;
	e->b = 39.9;
	e->color_set = 1;
	e->projection = 1;
}

void	ft_init(t_env *e)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	e->last_time = time.tv_sec + time.tv_usec * 1e-6;
	e->tab = NULL;
	e->line = 0;
	e->col = 0;
	ft_reset(e);
}

int		main(int ac, char **av)
{
	t_env e;

	if (ac == 1 || ac > 2)
	{
		ft_putstr("Error, select a map to display.\n");
		return (1);
	}
	ft_init(&e);
	if (ac == 2)
	{
		e.map = ft_strdup(av[1]);
		if (!get_map(&e, av[1]))
		{
			ft_putstr("Error, invalid file.\n");
			return (1);
		}
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
