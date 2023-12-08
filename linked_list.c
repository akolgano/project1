#include "push_swap.h"

int	linked_list_size(t_list *stack)
{
	if (stack == NULL)
		return (0);
	else
		return (1 + linked_list_size(stack->next));
}
t_list	*new_elem(int value)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	p->value = value;
	p->a_score = -1;
	p->b_score = -1;
	p->a_rscore = -1;
	p->b_rscore = -1;
	p->rank = -1;
	p->transfer_type = -1;
	p->next = NULL;
	return (p);
}
t_list	*get_last_elem(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	else
		return (get_last_elem(stack->next));
}

void	add_back(t_list **stack, t_list *new)
{
	t_list	*p;

	if (*stack == NULL)
		*stack = new;
	else
	{
		p = get_last_elem(*stack);
		p->next = new;
	}
}

t_list	*before_last_stack_elem(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (NULL);
	if (stack->next->next == NULL)
		return (stack);
	else
		return (before_last_stack_elem(stack->next));
}

void	stack_add_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}