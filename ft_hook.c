/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 13:12:19 by jwalle            #+#    #+#             */
/*   Updated: 2015/04/22 13:12:21 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->endian);
	draw(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	mlx_pixel_put(e->mlx, e->win, 2, 2, 0xFF0000);
	printf("key : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		e->zoom += 5;
	if (keycode == 78)
		e->zoom -= 5;
	if (keycode == 124)
		e->start_x += 20;
	if (keycode == 123)
		e->start_x -= 20;
	if (keycode == 126)
		e->start_y += 20;
	if (keycode == 125)
		e->start_y -= 20;
	if (keycode == 116)
		e->h += 0.1;
	if (keycode == 121)
		e->h -= 0.1;
	if (keycode == 47)
		e->z += 1;
	if (keycode == 43)
		e->z -= 1;
	if (keycode == 115)
		e->w += 0.1;
	if (keycode == 119)
		e->w -= 0.1;
	if (keycode == 263)
		e->g += 0.1;
	if (keycode == 117)
		e->g -= 0.1;
	expose_hook(e);
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	mlx_pixel_put(e->mlx, e->win, 2, 2, 0xFF0000);
	printf("mouse : %d (%d:%d)\n", button, x, y);
	return (0);
}
