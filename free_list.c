#include "fdf.h"

void	free_tab_char(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab_int(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
			free(tab[i]);
			i++;
	}
	free(tab);
}

