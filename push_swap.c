#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list    *head_a;
	
    head_a = readParams(argc, argv);
    if (checkIfNotPreSorted(head_a))
        sort(&head_a);

    finalSort(&head_a);
    //printf("After Final sort:\n");
    while (head_a)
    {
        printf("%d\n", head_a->value);
        head_a = head_a->next;
    }
    return 0;
}
