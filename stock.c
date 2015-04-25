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
	while (i < e->line - 2)
	{
		j = 0;
		while (j < e->tab[i][0] - 2)
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
	return (head);
}

t_point	*ll_copy_new(t_point *head, t_env *e, int i, int j)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	new->next = head;
	head = new;
	new->origin = get_position(i, j, e->tab[i][j]);
	new->right = get_position(i + 1, j, e->tab[i + 1][j]);
	new->down = get_position(i, j + 1, e->tab[i][j + 1]);
	return (new);
}

t_point	*ll_copy_cur(t_point *cur, t_env *e, int i, int j)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	cur->next = new;
	new->next = NULL;
	new->origin = get_position(i, j, e->tab[i][j]);
	new->right = get_position(i + 1, j, e->tab[i + 1][j]);
	new->down = get_position(i, j + 1, e->tab[i][j + 1]);
	return (new);
}

t_coord	*get_position(int x, int y, int z)
{
	t_coord *new;

	new = (t_coord*)malloc(sizeof(t_coord));
	new->x = x + 1;
	new->y = y;
	new->z = z;
	return (new);
}
