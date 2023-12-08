#include "push_swap.h"
int	*sort_array(int *array, int size, t_list *head)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < size)
	{
		array[i] = head->value;
		head = head->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
		}
	}
	return (array);
}
int	findMinMaxMed(t_list **head, int *min, int *max, int *med)
{
	int	size;
	int	*array;

	size = linked_list_size(*head);
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		return (1);
	array = sort_array(array, size, *head);
	*min = array[0];
	*max = array[size - 1];
	*med = array[size / 2];
	//insert_ranks(*head, array);
	//free(array);
	array = NULL;
	return (0);
}
