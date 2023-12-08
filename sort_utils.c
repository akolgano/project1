#include "push_swap.h"
#include <stdio.h>

/*int calculateScore()
{
	//calculateBScore;
	//calculateAScore;
}*/
t_list	*fillStackB(t_list **head_a)
{
	t_list	*head_b;
	int       min;
	int		  max;
	int		  med;
	int size_a;

	head_b = NULL;
	findMinMaxMed(head_a, &min, &max, &med);
	size_a = linked_list_size(*head_a);
	//push all values except min, med, max to Stack b
	while (size_a > 3)
	{
		if ((*head_a)->value == min || (*head_a)->value == med
			|| (*head_a)->value == max)
			ra(head_a);
		else
		{
			pb(head_a, &head_b);
			size_a--;
		}
	}
	miniSort(head_a);
	return (head_b);
}

void fullSort(t_list **head_a)
{
	t_list    *head_b;

	head_b = NULL;
	head_b = fillStackB(head_a);
	while (head_b)
	{
		process(head_a, &head_b);
		//head_b = head_b->next;
	}
}