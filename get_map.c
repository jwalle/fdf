#include "fdf.h"

int		nb_space(char *str);
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

int		*ft_fill(char *str)
{
	int *tab;
	int max;
	int i;

	i = -1;
	max = nb_space(str) + 1);
	tab = (int*)malloc((max + 1) * (sizeof(*tab))));
	tab[0] = max;
	while (++i <= max)
		tab[i] = ft_atoi(plop);
	return (tab);
}

int		ft_line_count(int fd)
{
	int len;
	char *line;

	len = 0;
	while (get_next_line(fd, &line) == 1);
	{
		free(line);
		len++;
	}
	if (line)
		len++;
	return (len);
}

char *get_map(t_env *e)
{
	int		fd;
	char	*temp;
	char 	*str;
	int		max;
	int 	i;

	str = "test_maps/pnp_flat.fdf";
	fd = open(str, O_RDONLY);
	max = ft_line_count(fd);
	if (!(e->tab = (int**)malloc(sizeof(int*) * (max + 1))))
		return (NULL); //ft_error...
	e->tab[max] = '\0';
	i = 0;
	while (get_next_line(fd, &temp) == 1)
	{
		e->tab[i] = ft_fill(temp, i, e);
		i++;
		free(temp);
		temp = NULL;
	}
	return (NULL);
}

