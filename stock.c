#include "fdf.h"

t_point	*ll_stock(t_env *e)
{
	t_point			*head;
	t_point			*current;
	int i;
	int j;

	head = NULL;
	current = head;
	i = 0;
	while (i <= e->line)
	{
		j = 1;
		while (j <= e->tab[0][0])
		{
			if (head == NULL)
			{
				head = ll_copy_new(head, e, i, j);
				current = head;
			}
			else
			{
				while (current->next != NULL)
					current = current->next;
				current = ll_copy_cur(current, e, i, j);
			}
			j++;
		}
		i++;
	}
	printf("test stock\n");
	return (head);
}

t_point	*ll_copy_new(t_point *head, t_env *e, int i, int j)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	new->next = head;
	head = new;
	new->origin = get_position(i, j, e->tab[i][j], e);
	new->right = get_position(i + 1, j, e->tab[i + 1][j], e);
	new->down = get_position(i, j + 1, e->tab[i][j + 1], e);
	return (new);
}

t_point	*ll_copy_cur(t_point *cur, t_env *e, int i, int j)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	cur->next = new;
	new->next = NULL;
	
	if (i < e->line)
		new->origin = get_position(i, j, e->tab[i][j], e);
	
	if (i < e->line - 1)
		new->right = get_position(i + 1, j, e->tab[i + 1][j], e);
	else
		new->right = NULL;
	
	if (i < e->line && j < e->col)
		new->down = get_position(i, j + 1, e->tab[i][j + 1], e);
	else
		new->down = NULL;
	return (new);
}

t_coord	*get_position(int x, int y, int z, t_env *e)
{
	t_coord *new;
	//double	temp;

	new = (t_coord*)malloc(sizeof(t_coord));
	//printf("malloc = t_coord\n");
	new->x = (x + 1);
	new->y = y;
	new->z = z;

	printf("x = %d\n", e->start_x);
	printf("y = %d\n", e->start_y);

	new->x = ((new->x * e->zoom) + (new->y * e->zoom) + e->start_y);
	//new->x = ((x + 1) * e->zoom) + (y * e->zoom) + e->start_y;
	new->y = ((e->h / 0.5) * (new->y * e->zoom) + e->start_x);
	//new->y = ((e->h / 0.5) * (y * e->zoom) + e->start_x);
	new->y *= e->g;
	//temp = new->x;
	//new->x = (e->g * new->x) - (e->w * new->y);
	//new->y = (e->z * new->z) + ((e->g / 2) * temp) + ((e->w / 2) * new->y);
	new->x = new->x + (e->z * new->z);
	new->y = new->y + ((e->z / 2) * new->z);
	
	return (new);
}
