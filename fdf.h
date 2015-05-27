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
#define WINDOW_SIZE_X 1500
#define WINDOW_SIZE_Y 2000

#include "minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"


typedef struct	s_coord
{
	double 		x;
	double 		y;
	int			z;
	int			k;
	int			s;
	int			i;
	int			j;
}				t_coord;

typedef struct	s_env
{
	int			color_set;
	int			start_x;
	int			start_y;
	int			line;
	int			col;
	int			zoom;
	double		h;
	void		*mlx;
	void		*win;
	void		*img;
	int 		bpp;
	int 		sl;
	int 		endian;
	char		*change;
	char 		*data;
	int			**tab;
	int			SIZE_Y;
	int			SIZE_X;
	double		w;
	double		z;
	double		g;
	double		a;
}				t_env;

int			get_map(t_env *e, char *str);
int			get_next_line(int const fd, char **line);
int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
void		draw(t_env *e);
void		pxl_to_image(t_env *e, int x, int y, uint32_t color);
void		draw_case_one(t_env *e, t_coord *ori, t_coord *dest);
uint32_t	ft_get_color(int z, t_env *e);
t_coord		*get_position(int x, int y, int z, t_env *e);
void		select_draw(t_coord *ori, t_coord* dest, t_env *e);
void		free_tab_int(int **tab);
void		free_tab_char(char **tab);
void		draw_case_one(t_env *e, t_coord *ori, t_coord *dest);
void		draw_case_two(t_env *e, t_coord *ori, t_coord *dest);
void		draw_case_three(t_env *e, t_coord *ori, t_coord *dest);
void		draw_case_four(t_env *e, t_coord *ori, t_coord *dest);



#endif
