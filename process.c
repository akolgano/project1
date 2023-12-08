#include "push_swap.h"
#include <stdio.h>
void calculateScoreinB(t_list *head_b)
{
	int i;
	int size;

	i = 0;
	size = linked_list_size(head_b);
	while (head_b)
	{
		head_b->b_score = i;
		head_b->b_rscore = size - i;
		head_b = head_b->next;
		i++;
	}
}
void calculateScoreinA(t_list *head_a,t_list *head_b)
{
	int i;
	int size;
	int prev;
	t_list *position;

	size = linked_list_size(head_a);
	position = head_a;
	while (head_b)
	{
		head_a = position;
		i = 0;
		prev = get_last_elem(head_a)->value;
		while (head_a)
		{
			if (head_b->value > prev && head_b->value <head_a->value)
			{
				head_b->a_score = i;
		        head_b->a_rscore = size - i;
			}
			i++;
			prev = head_a->value;
			head_a = head_a->next;
		}
		head_b = head_b->next;
	}
}

void just_print(t_list *head_a, t_list *head_b)
{
	printf("---------------score b = ");
	printf("%d\n", head_b->value);
	printf("%d\n", head_b->b_score);
	printf("%d\n", head_b->b_rscore);
	printf("%d\n", head_b->rank);
	printf("%d\n", head_b->transfer_type);
	printf("---------------score a = ");
	printf("%d\n", head_a->value);
	printf("%d\n", head_a->b_score);
	printf("%d\n", head_a->b_rscore);
}
void print_elem(t_list *head_b)
{
	printf("Moving element ");
	printf("%d", head_b->value);
	printf(" b_score = %d", head_b->b_score);
	printf(" b_rscore = %d", head_b->b_rscore);
	printf(" rank = %d", head_b->rank);
	printf(" transfer_type = %d \n", head_b->transfer_type);
}

void print_list(t_list *head)
{
	printf("------------------------------------------------------------------\n");
	while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    	printf("\n");
    printf("------------------------------------------------------------------\n");
}
void	process(t_list **head_a, t_list **head_b)
{
	t_list	*elem;
	//int size_a;
	//int size_b;
	//int				transfer_type;
	//printf("------------Process-------------------\n");
	//print_list(*head_a);
	//print_list(*head_b);
	calculateScoreinB(*head_b);
	calculateScoreinA(*head_a, *head_b);
	//printf("Making decision");
	elem = make_decision(*head_b);
	//printf("Value in a: \n");
	//print_list(*head_a);
	//printf("Value in b: \n");
	//print_list(*head_b);
	//print_elem(elem);
	moveElementToStackA(head_a, head_b, elem);
	//size_b = linked_list_size(*head_b);
	//size_a = linked_list_size(*head_a);
	//printf("SIZE A:                           %d\n", size_a);
	//printf("SIZE B:                           %d\n", size_b);
	//printf("Value in a: \n");
	//print_list(*head_a);
	//printf("Value in b: \n");
	//print_list(*head_b);
}