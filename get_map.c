#include "fdf.h"

int		nb_space(char *str)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	return (space);
}

int		*ft_fill(char *str, t_env *e)
{
	int *tab;
	int i;
	char **tab_line;

	tab_line = ft_strsplit(str, ' ');
	i = 0;
	e->col = nb_space(str) + 1;
	tab = ((int*)malloc((e->col + 1) * (sizeof(*tab))));
	tab[0] = e->col;
	while (++i <= e->col)
		tab[i] = ft_atoi(tab_line[i - 1]);
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
	if (line)
		len++;
	return (len);
}

void get_map(t_env *e)
{
	int		fd;
	char	*temp;
	char 	*str;
	int 	i;

	str = "test_maps/42.fdf";
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
}

