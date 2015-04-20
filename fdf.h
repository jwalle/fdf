/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 12:17:57 by jwalle            #+#    #+#             */
/*   Updated: 2015/04/20 12:18:05 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "minilibx_macos/mlx.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;


int		get_next_line(int const fd, char **line);

#endif
