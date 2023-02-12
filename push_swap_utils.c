#include "push_swap.h"

int check_isdigits(char *str)
{
    int i = -1;
    while (str[++i])
        if (ft_isdigit(str[i]) == 0 && str[0] != '+' && str[0] != '-')
            return (0);
    return (1);
}

int get_num_count(char   **num)
{
    int i = -1;
    while (num[++i]);
    return (i);
}

void    ft_swap(char   **str1, char **str2)
{
    char    *tmp;

    tmp = ft_strjoin(*str1, *str2);
    free(*str1);
    *str1 = tmp;
}

char    *get_all_args(int ac, char **av)
{
    char    *res = malloc(1);
    int     i = 1;
    char    *space = " ";

    if (ac == 2)
        return (ft_strdup(av[1]));
    while (i < ac)
    {
        ft_swap(&res, &space);
        ft_swap(&res, &av[i]);
        i++;
    }
    return (res);
}

int	get_min_number(t_stack *stack, int *index)
{
	int i = stack->top;
	int lowest = stack->stack[i];
	int n = i;
	while (i > -1)
	{
		if (lowest > stack->stack[i])
		{
			lowest = stack->stack[i];
			n = i;
		}
		i--;
	}
	*index = n;
	return (lowest);
}

int	get_max_number(t_stack *stack, int *index)
{
	int i = stack->top;
	int bigest = stack->stack[i];
	int n = i;
	while (i > -1)
	{
		if (bigest < stack->stack[i])
		{
			bigest = stack->stack[i];
			n = i;
		}
		i--;
	}
	*index = n;
	return (bigest);
}

int get_index_of_operation(int *res, int len)
{
	int small = res[0];
	int idx = 0;
	int i = 0;
	while (i <= len)
	{
		if (res[i] <= small)
		{
			small = res[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int get_number_of_operation(int res[4])
{
	int small = res[0];
	int idx = 0;
	int i = 0;
	while (i < 4)
	{
		if (res[i] <= small)
		{
			small = res[i];
			idx = i;
		}
		i++;
	}
	return (small);
}