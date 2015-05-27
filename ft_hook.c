/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 13:12:19 by jwalle            #+#    #+#             */
/*   Updated: 2015/04/27 19:17:18 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->endian);
	draw(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		exit(0);
	}
	if (keycode == 69)
		e->zoom += 2;
	if (keycode == 78)
		e->zoom -= 2;
	if (keycode == 124)
		e->start_x += 40;
	if (keycode == 123)
		e->start_x -= 40;
	if (keycode == 126)
		e->start_y += 40;
	if (keycode == 125)
		e->start_y -= 40;
	if (keycode == 116)
		e->h += 0.1;
	if (keycode == 121)
		e->h -= 0.1;
	if (keycode == 47)
		e->z += 1;
	if (keycode == 43)
		e->z -= 1;
	if (keycode == 6)
		e->z += 0.1;
	if (keycode == 7)
		e->z -= 0.1;
	if (keycode == 115)
		e->w += 0.1;
	if (keycode == 119)
		e->w -= 0.1;
	if (keycode == 263)
		e->g += 0.1;
	if (keycode == 117)
		e->g -= 0.1;
	if (keycode == 0)
		e->a += 0.1;
	if (keycode == 2)
		e->a -= 0.1;
	if (keycode == 18)
		e->color_set = 1;
	if (keycode == 19)
		e->color_set = 2;
	if (keycode == 20)
		e->color_set = 3;
	printf("x = %d,y = %d, zoom = %d\n", e->start_x, e->start_y, e->zoom);
	printf("col = %d, line = %d\n", e->col, e->line);
	mlx_destroy_image(e->mlx, e->img);
	expose_hook(e);
	return (0);
}

/* A retirer */

int mouse_hook(int button, int x, int y, t_env *e)
{
	mlx_pixel_put(e->mlx, e->win, 2, 2, 0xFF0000);
	printf("mouse : %d (%d:%d)\n", button, x, y);
	return (0);
}
