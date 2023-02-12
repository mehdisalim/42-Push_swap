#include "push_swap.h"

void    ft_copy(int *dest, int *src, int len)
{
	int i = -1;
	while (++i <= len)
		dest[i] = src[i];
}

int		get_middle_of_arr(t_stack *stack_a, int *tmp)
{
    int value = 0;
    int i = -1;
    while (++i <= stack_a->top)
    {
        if (i + 1 <= stack_a->top && tmp[i] > tmp[i + 1])
		{
			value = tmp[i];
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = value;
			i = -1;
		}
    }
	value = tmp[i / 2];
	return (value);
}

int		get_less_than_middle(t_stack *stack_a, int value)
{
	int res = 0;
	int i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->stack[i] < value)
			res++;
		i++;
	}
	return (res);
}

void	chunck_algo(t_stack *stack_a, t_stack *stack_b)
{
	int middle = 0;
	int res = 0;
	int len = stack_a->top;
    int *tmp = malloc((len + 1) * 4);
	while (stack_a->top > 2)
	{
		if (res == 0)
		{
			ft_copy(tmp, stack_a->stack, stack_a->top);
			middle = get_middle_of_arr(stack_a, tmp);
			res = get_less_than_middle(stack_a, middle);
		}
		if (stack_a->stack[stack_a->top] <= middle)
		{
			pb(stack_b, stack_a);
			res--;
		}
		else
			ra(stack_a);
	}
	free(tmp);
	if (stack_a->top == 2)
		sort_three(stack_a);
}