#include "push_swap.h"

void	ra(t_list **head)
{
	t_list	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		add_back(head, tmp);
		write(1, "ra\n", 3);
	}
}
void	rb(t_list **head)
{
	t_list	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		add_back(head, tmp);
		write(1,"rb\n", 3);
	}
}

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*p;
	t_list	*p2;

	if (*head_a)
	{
		p = *head_b;
		p2 = *head_a;
		(*head_a) = (*head_a)->next;
		(*head_b) = p2;
		(*head_b)->next = p;
		write(1, "pb\n", 3);
	}	
	//printf("size of a after pb: %d\n", linked_list_size(*head_a));
	//printf("size of b after pb: %d\n", linked_list_size(*head_b));
}

void	sa(t_list **head_a)
{
	t_list	*p;
	t_list	*next;

	p = *head_a;
	if (*head_a && (*head_a)->next)
	{
		next = (*head_a)->next;
		(*head_a)->next = next->next;
		next->next = p;
		(*head_a) = next;
		write(1, "sa\n", 3);
	}
}

void	rra(t_list **head_a)
{
	t_list	*before_last;

	if (*head_a && (*head_a)->next)
	{
		//TODO
		before_last = before_last_stack_elem(*head_a);
		stack_add_front(head_a, before_last->next);
		before_last->next = NULL;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **head)
{
	t_list	*before_last;

	if (*head && (*head)->next)
	{
		before_last = before_last_stack_elem(*head);
		stack_add_front(head, before_last->next);
		before_last->next = NULL;
		write(1, "rrb\n", 4);
	}
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*p;
	t_list	*p2;
	//int v;

	if (*head_b)
	{
		p = *head_a;
		p2 = *head_b;
		//v = p2->value;
		(*head_b) = (*head_b)->next;
		(*head_a) = p2;
		(*head_a)->next = p;

		write(1, "pa\n", 3);
	}
	//printf("size of a after pa: %d\n", linked_list_size(*head_a));
	//printf("size of b after pa: %d\n", linked_list_size(*head_b));
	//printf("v = %d\n", v);
}

void	rr(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		tmp->next = NULL;
		add_back(head_a, tmp);
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		tmp->next = NULL;
		add_back(head_b, tmp);
		flag += 2;
	}
	if (flag == 1)
		write(1, "ra\n", 3);
	if (flag == 2)
		write(1, "rb\n", 3);
	if (flag == 3)
		write(1, "rr\n", 3);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	t_list	*before_last;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		before_last = before_last_stack_elem(*head_a);
		stack_add_front(head_a, before_last->next);
		before_last->next = NULL;
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		before_last = before_last_stack_elem(*head_b);
		stack_add_front(head_b, before_last->next);
		before_last->next = NULL;
		flag += 2;
	}
	if (flag == 1)
		write(1, "rra\n", 4);
	if (flag == 2)
		write(1, "rrb\n", 4);
	if (flag == 3)
		write(1, "rrr\n", 4);
}