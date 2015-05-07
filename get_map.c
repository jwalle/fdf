/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 13:12:26 by jwalle            #+#    #+#             */
/*   Updated: 2015/04/27 14:24:44 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		*ft_fill(char *str, t_env *e)
{
	int *tab;
	int i;
	int j;
	char **tab_line;

	tab_line = ft_strsplit(str, ' ');
	j = print_tab(tab_line);
	if (e->col < j)
		e->col = j;
	i = 0;
	tab = ((int*)malloc((j + 1) * (sizeof(*tab))));
	tab[0] = j;
	while (++i <= j)
	{
		tab[i] = ft_atoi(tab_line[i - 1]);
		if (!tab[i])
			tab[i] += 1;
	}
	free_tab_char(tab_line);
	return (tab);
}

int		ft_line_count(int fd)
{
	int len;
	char *line;

	len = 0;
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		len++;
	}
	return (len);
}

void get_map(t_env *e, char *str)
{
	int		fd;
	char	*temp;
	int 	i;

	fd = open(str, O_RDONLY);	
	e->line = ft_line_count(fd);
	if (!(e->tab = (int**)malloc(sizeof(int*) * (e->line + 1))))
		return ; //ft_error...
	e->tab[e->line] = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &temp) == 1)
	{
		e->tab[i] = ft_fill(temp, e);
		i++;
		free(temp);
		temp = NULL;
	}
	//e->start_x = (WINDOW_SIZE_X / e->line) * 5;
	//e->start_y = (WINDOW_SIZE_Y / e->tab[0][0]) * 5;
	//e->zoom = (e->line * e->col) / WINDOW_SIZE_Y;
}

