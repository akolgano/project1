#include "push_swap.h"

int checkIfNotPreSorted(t_list *head_a)
{
	t_list *p;
	int flag;

	flag= 0;
	p = head_a;
	while (head_a && head_a->next)
	{
		if (head_a->value > head_a->next->value && flag)
			return 1;
		if (head_a->value > head_a->next->value)
			flag = 1;
		head_a = head_a->next;
	}
	if (head_a && head_a->value > p->value && flag)
		return (1);
	return (0);
}

void	miniSort(t_list **head_a)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = linked_list_size(*head_a);
	if (size == 3)
	{
		first = (*head_a)->value;
		second = (*head_a)->next->value;
		third = (*head_a)->next->next->value;
		if (second > third && second > first && third > first)
			sa(head_a);
		if (third > first && third > second && first > second)
			sa(head_a);
		if (first > third && first > second && second > third)
			sa(head_a);
	}
}
void sort(t_list **head_a)
{
	int size;
	size = linked_list_size(*head_a);
	if (size == 3)
		miniSort(head_a);
	else
		fullSort(head_a);
}

//final rotation in stack A 
void	finalSort(t_list **head)
{
	t_list	*p;
	int				min;
	int				max;
	int				count;
	int				size;
	int             med;
	findMinMaxMed(head, &min, &max, &med);
	p = *head;
	count = 0;
	//printf("min = %d\n", min);
	//printf("%d\n", p->value);
	while (p->value != min)
	{
		//printf("count = %d\n", count);
		count++;
		p = p->next;
	}
	size = linked_list_size(*head);
	//printf("size:%d\n", size);
	if (count <= size - count)
		while (count > 0)
		{
			ra(head);
			count--;
		}
	else
	{
		//printf("Using rra");
		while (count < size)
		{
			rra(head);
			count++;
		}
	}
}