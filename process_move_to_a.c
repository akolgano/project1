#include "push_swap.h"

int getTransferType(t_list *head_b)
{
	return (head_b->transfer_type);
}
void	moveElementToStackA(t_list **head_a, t_list **head_b,
	t_list *elem)
{
	int tt;

	tt = getTransferType(*head_b);
	if ( tt== 1)
	{
		while (elem->a_score-- > 0 && elem->b_score--)
			rr(head_a, head_b);
		while (elem->b_score-- > 0)
			rb(head_b);
	}
	if (tt == 2)
	{
		while (elem->b_score-- > 0 && elem->a_score--)
			rr(head_a, head_b);
		while (elem->a_score-- > 0)
			ra(head_a);
	}
	if (tt == 3)
	{
		while (elem->a_rscore-- > 0 && elem->b_rscore--)
			rrr(head_a, head_b);
		while (elem->b_rscore-- > 0)
			rrb(head_b);
	}
	if (tt == 4)
	{
		while (elem->b_rscore-- > 0 && elem->a_rscore--)
			rrr(head_a, head_b);
		while (elem->a_rscore-- > 0)
			rra(head_a);
	}
	if (tt == 5)
	{
		while (elem->b_score-- > 0)
			rb(head_b);
		while (elem->a_rscore-- > 0)
			rra(head_a);
	}
	if (tt == 6)
	{
		while (elem->b_rscore-- > 0)
			rrb(head_b);
		while (elem->a_score-- > 0)
			ra(head_a);
	}
	pa(head_a, head_b);
}