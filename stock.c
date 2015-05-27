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

	new = (t_coord*)malloc(sizeof(t_coord));
	new->x = (x + 1);
	new->y = y;
	new->z = z;
	new->x = (new->x * e->zoom) + (new->y * e->zoom) + e->start_y;
	new->y = (e->h / 0.5) * (new->y * e->zoom) + e->start_x;
	new->y *= e->g;
	new->x = new->x + (e->z * new->z);
	new->y = new->y + ((e->z / 2) * new->z);
	return (new);
}
