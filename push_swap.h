#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct t_list
{
	struct t_list	    *next;
	int					value;
	int					a_score;
	int					a_rscore;
	int					b_score;
	int					b_rscore;
	int					rank;
	int                 transfer_type;
}	t_list;

//parse_input.c
t_list *readParams(int argc, char **argv);

int ft_atoi(char *s);

//sort.c
int calculateScore();

//sort.c
int checkIfNotPreSorted(t_list *head_a);
void sort(t_list **head_a);

void	miniSort(t_list **head_a);
void	finalSort(t_list **head);

//linked_list.c
int	linked_list_size(t_list *stack);
t_list	*new_elem(int value);
t_list	*get_last_elem(t_list *stack);
void	add_back(t_list **stack, t_list *new);
void	stack_add_front(t_list **stack, t_list *new);
t_list	*before_last_stack_elem(t_list *stack);

//operations.c
void	sa(t_list **head_a);
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);
void	ra(t_list **head);
void	rb(t_list **head);
void	rra(t_list **head_a);
void	rrb(t_list **head);
void	rr(t_list **head_a, t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);


//utils.c
int	*sort_array(int *array, int size, t_list *head);
int	findMinMaxMed(t_list **head, int *min, int *max, int *med);


//sort_utils.c
t_list	*fillStackB(t_list **head_a);
void fullSort(t_list **head_a);

//process.c
void	process(t_list **head_a, t_list **head_b);
void calculateScoreinB(t_list *head_b);
void calculateScoreinA(t_list *head_a,t_list *head_b);

//process2.c
int	total_score_elem(t_list *head);
t_list	*make_decision(t_list *head);

//process_move_to_a.c
void	moveElementToStackA(t_list **head_a, t_list **head_b,
	t_list *elem);

#endif