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
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_init(t_env *e)
{
	e->tab = NULL;
	e->line = 0;
	e->col = 0;
}

void	print_map(t_env *e)
{
	int i;
	int j;


	i = 0;
	printf("plop\n");
	while (i <= e->line - 2)
	{
		j = 0;
		//while (j <= e->col)
		while (j <= e->tab[i][0])
		{
			printf("%d", e->tab[i][j]);
			printf(" ");
			j++;
		}
		i++;
		printf("\n");
	}
}

int main()
{
	t_env e;

	ft_init(&e);	
	get_map(&e);
	print_map(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

// http://perso.epitech.eu/~ol/work/raytracer/cours/cours/
