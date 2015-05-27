/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:53:03 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/27 15:53:14 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_case_one(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->x;
	while (x <= dest->x)
	{
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) /
			(dest->x - ori->x), ft_get_color(dest->z, e));
		x++;
	}
}

void	draw_case_two(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->x;
	while (x <= ori->x)
	{
		pxl_to_image(e, x, ori->y + ((dest->y - ori->y) * (x - ori->x)) /
			(dest->x - ori->x), ft_get_color(dest->z, e));
		x++;
	}
}

void	draw_case_three(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = ori->y;
	while (x <= dest->y)
	{
		pxl_to_image(e, ori->x + ((dest->x - ori->x) * (x - ori->y)) /
			(dest->y - ori->y), x, ft_get_color(dest->z, e));
		x++;
	}
}

void	draw_case_four(t_env *e, t_coord *ori, t_coord *dest)
{
	int x;

	x = dest->y;
	while (x <= ori->y)
	{
		pxl_to_image(e, ori->x + ((dest->x - ori->x) * (x - ori->y)) /
			(dest->y - ori->y), x, ft_get_color(dest->z, e));
		x++;
	}
}
