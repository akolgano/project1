#include "push_swap.h"

int ft_atoi(char *s)
{
	int i;
	int mod;
	int res;

	i = 0;
	mod = 1;
	res = 0;
	if (s[i] == '-')
	{
		mod = -1;
		i++;
	}
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		res = res*10 + (s[i] - '0');
		i++;
	}
	return (res*mod);
}