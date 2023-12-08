#include "push_swap.h"
#include <stdio.h>

t_list *readParams(int argc, char **argv)
{
	t_list *head;
	int i;

	head = NULL;
	i = 0;
	//printf("%s\n", argv[1]);
	if (argc < 2)
	{
		write(1, "Error\n", 6);
	}
	if (argc == 2)
	{
		//TODO
		//str = ft_strjoin("!push_swap ", argv[1]);
		//argv = ft_split(str, ' ');
		//free(str);
		//argc = splited_size(argv);
	}
	i = 1;
	while (i < argc)
	{
		//printf("%d\n", ft_atoi(argv[i]));
		add_back(&head, new_elem(ft_atoi(argv[i])));
		i++;
	}
	return (head);
}

