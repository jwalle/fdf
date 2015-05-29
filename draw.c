/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:57:34 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/27 15:57:36 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		absolute(int res)
{
	if (res < 0)
		res *= (-1);
	return (res);
}

void	select_draw(t_coord *ori, t_coord *dest, t_env *e)
{
	if (dest != NULL && ori != NULL)
	{
		if ((absolute(dest->x - ori->x)) >= (absolute(dest->y - ori->y)))
		{
			if (ori->x < dest->x)
				draw_case_one(e, ori, dest);
			else
				draw_case_two(e, ori, dest);
		}
		else
		{
			if (ori->y < dest->y)
				draw_case_three(e, ori, dest);
			else
				draw_case_four(e, ori, dest);
		}
		free(ori);
		free(dest);
	}
}

void	draw(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i <= e->line - 1)
	{
		j = 1;
		while (j <= e->tab[i][0])
		{
			if (j < e->tab[i][0])
				select_draw(get_position_ori(i, j, e->tab[i][j], e),
					get_position_right(i, j + 1, e->tab[i][j + 1], e), e);
			if (i < e->line - 1 && j <= e->tab[i + 1][0])
				select_draw(get_position_ori(i, j, e->tab[i][j], e),
					get_position_down(i + 1, j, e->tab[i + 1][j], e), e);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
