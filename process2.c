#include "push_swap.h"

int	total_score_elem(t_list *head)
{
	int	result;
	int	biggest_rscore;

	result = head->b_score;
	head->transfer_type = 1;
	if (head->a_score >= head->b_score)
	{
		result = head->a_score;
		//*ttype = 2;
		head->transfer_type = 2;
	}
	biggest_rscore = head->a_rscore;
	if (head->b_rscore > biggest_rscore)
		biggest_rscore = head->b_rscore;
	if (result > biggest_rscore)
	{
		result = biggest_rscore;
		if (head->b_rscore > head->a_rscore)
			//*ttype = 3;
			head->transfer_type = 3;
		else
			//*ttype = 4;
			head->transfer_type = 4;
	}
	//result = total_score_elem2(result, head, ttype);
	//printf("%d\n", result);
	if (head->b_score + head->a_rscore < result)
	{
		result = head->b_score + head->a_rscore;
		head->transfer_type = 5;
	}
	if (head->b_rscore + head->a_score < result)
	{
		result = head->b_rscore + head->a_score;
		head->transfer_type = 6;
	}
	return (result);
}

t_list	*make_decision(t_list *head)
{
	t_list	*save_point;
	int				best_total_score;
	int				best_rank;
	//int				best_transfer_type;

	best_total_score = total_score_elem(head);
	best_rank = head->rank;
	//best_transfer_type = *transfer_type;
	//best_transfer_type = head->transfer_type;
	save_point = head;
	while (head)
	{
		if (total_score_elem(head) < best_total_score
			|| (total_score_elem(head) == best_total_score
				&& head->rank >= best_rank))
		{
			best_total_score = total_score_elem(head);
			best_rank = head->rank;
			//best_transfer_type = head->transfer_type;
		}
		head = head->next;
	}
	//*transfer_type = best_transfer_type;
	while (save_point->rank != best_rank)
		save_point = save_point->next;
	return (save_point);
}