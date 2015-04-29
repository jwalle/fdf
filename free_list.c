#include "fdf.h"

void free_list(t_point *current)
{
	t_point	*temp;

	printf("free_list start.\n");
	while ((t_point*)current != NULL)
	{
		printf("plop\n");
		
		temp = (void *)current;
		current = current->next;
		//free(current->origin);
		//free(current->right);
		//free(current->down);
		temp = NULL;
		free(temp);

		printf("free t_coord\n");
	}
	printf("free t_point\n");
}

void free_tab_int(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
			free(tab[i]);
			i++;
	}
	free(tab);
	printf("OK\n");
}
