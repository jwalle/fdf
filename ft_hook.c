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

void	ft_print_screen(t_env *e)
{
	double	current_time;
	double	fps;
	struct	timeval time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec + time.tv_usec * 1e-6;
	fps = 1 / (current_time - e->last_time);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFF0000, ft_itoa(fps));
	mlx_string_put(e->mlx, e->win, 45, 10, 0xFF0000, e->map);
	if (e->color_set == 1)
		mlx_string_put(e->mlx, e->win, 10, 40, 0x000FE1, "Color set = cartographie gradient");
	if (e->color_set == 2)
		mlx_string_put(e->mlx, e->win, 10, 40, 0xF5F4F2, "Color set = HSV gradient");
	if (e->color_set == 3)
		mlx_string_put(e->mlx, e->win, 10, 40, 0x0096E1, "Color set = HSV reverse gradient");
	e->last_time = current_time;
}

int expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->endian);
	draw(e);
	ft_print_screen(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if (keycode == 53)
	{
		free_tab_int(e->tab);
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 69)
		e->zoom += 1;
	if (keycode == 78)
		e->zoom -= 1;
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
	if (keycode == 13) // son y
		e->w += 0.1;
	if (keycode == 12) // son y
		e->w -= 0.1;
	if (keycode == 1) // son z
		e->g += 11;
	if (keycode == 0) // son z
		e->g -= 10;
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
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	expose_hook(e);
	return (1);
}
