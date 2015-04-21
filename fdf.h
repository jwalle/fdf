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
# define IMG_SIZE_X 10
# define IMG_SIZE_Y 10

#include "minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minilibx_macos/mlx.h"
#include "get_next_line.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int 		bpp;
	int 		sl;
	int 		endian;
	char		*change;
	char 		*data;


}				t_env;


int		get_next_line(int const fd, char **line);
int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
void 	draw(t_env *e);


#endif
