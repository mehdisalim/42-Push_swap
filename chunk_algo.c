#include "push_swap.h"

void    ft_copy(t_stack *tmp, t_stack *src)
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
	// free(tmp->stack);
	return (value);
}

void	chunck_algo(t_stack *stack_a, t_stack *stack_b)
{
	int middle;
	while (stack_a->top > 2)
	{
		middle = get_middle_of_arr(stack_a);
		if (stack_a->stack[stack_a->top] < middle)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	if (stack_a->top == 2)
		sort_three(stack_a);
}