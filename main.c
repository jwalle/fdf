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

void	ft_init(t_env *e)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	e->last_time = time.tv_sec + time.tv_usec * 1e-6;
	e->tab = NULL;
	e->line = 0;
	e->col = 0;
	e->zoom = 10;
	e->h = 1.5;
	e->start_x = 100;
	e->start_y = 100;
	e->z = -4;
	e->w = 0;
	e->g = 20;
	e->a = 2;
	e->color_set = 1;
}

void	ft_reset(t_env *e)
{
	e->zoom = 10;
	e->h = 1.5;
	e->start_x = 100;
	e->start_y = 100;
	e->z = -4;
	e->w = 0;
	e->g = 20;
	e->a = 2;
	e->color_set = 1;
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
