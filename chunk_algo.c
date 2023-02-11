#include "push_swap.h"

int	get_min_index(t_stack *stack)
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
	return (n);
}

void	ft_copy(t_stack *tmp, t_stack *src)
{
	int i = 0;
	while (i <= src->top)
		push(tmp, src->stack[i++]);
}

int	get_middle_of_arr(t_stack *stack_a)
{
    t_stack *tmp = oncreate(stack_a->capacity);
	ft_copy(tmp, stack_a);
    int value;
    int i = -1;
    while (++i <= tmp->top)
    {
        if (i + 1 <= tmp->top && tmp->stack[i] > tmp->stack[i + 1])
		{
			value = tmp->stack[i];
			tmp->stack[i] = tmp->stack[i + 1];
			tmp->stack[i + 1] = value;
			i = -1;
		}
    }
	value = tmp->stack[i / 2];
	free(tmp->stack);
	return (value);
}
