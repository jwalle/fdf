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
	e->img = mlx_new_image(e->mlx, 400, 400);
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
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	mlx_pixel_put(e->mlx, e->win, 2, 2, 0xFF0000);
	printf("mouse : %d (%d:%d)\n", button, x, y);
	return (0);
}
