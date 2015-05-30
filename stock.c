/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:06:31 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/27 16:06:33 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*get_position(int x, int y, int z, t_env *e)
{
	t_coord	*new;
	int		xx;

	new = (t_coord*)malloc(sizeof(t_coord));
	new->x = (x + 1);
	new->y = y;
	new->z = z;
	xx = new->x;
	new->x = xx * cos(e->w) - new->y * sin(e->w);
	new->y = xx * sin(e->w) + new->y * cos(e->w);
	new->x = e->start_y + (new->x * e->zoom) + (new->y * e->zoom);
	new->y = e->start_x + (e->h / 2) * (new->y * e->zoom);
	xx = new->x;
	if (e->projection == 1)
	{
		new->x = (e->g * xx) * cos(e->a) - new->y * cos(e->b);
		new->y = (e->z * new->z) + (e->g * xx) * sin(e->a)
		+ new->y * sin(e->b);
	}
	if (e->projection == 2)
	{
		new->x = new->x + (e->z * new->z);
		new->y = new->y + ((e->z / 2) * new->z);
	}
	return (new);
}

//git add -A ; git commit -m "hop" ; git push origin noll
