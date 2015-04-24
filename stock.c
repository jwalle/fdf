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
	while (i <= e->line - 1)
	{
		j = 0;
		while (j <= e->tab[i][0])
		{
			if (head == NULL)
			{
				head = ll_copy_new(e, head, i, j);
				current = head;
			}
			else
			{
				while (current->next != NULL)
					current = current->next;
				current = ll_copy_cur(e, current, i, j);
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

	new->right->x1 = i;
	new->right->y1 = j;
	new->right->x2 = i + 1;
	new->right->y2 = j + 1;
	new->right->z1 = e->tab[i][j];
	new->right->z2 = e->tab[i][j + 1];

	return (new);
}

t_point	*ll_copy_cur(t_point *cur, t_env *e, int i, int j)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	cur->next = new;
	new->next = NULL;

	new->filename = ft_strdup(str);

	return (new);
}
