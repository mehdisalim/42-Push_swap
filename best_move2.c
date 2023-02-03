#include "push_swap.h"

int	get_min_number(t_stack *stack)
{
	int i = stack->top;
	int lowest = stack->stack[i];
	while (i > -1)
	{
		if (lowest > stack->stack[i])
			lowest = stack->stack[i];
		i--;
	}
	return (lowest);
}


t_retations get_position_in_b(t_stack *stack_b, int value)
{
	int pre_v = get_min_number(stack_b);
	t_retations rt_b;
	int i = stack_b->top;
	int *arr = stack_b->stack;
	int n = i;
	while (i > -1)
	{
		if (pre_v <= arr[i] && arr[i] < value)
		{
			pre_v = arr[i];
			n = i;
		}
		i--;
	}
	rt_b.rb = stack_b->top - n;
	rt_b.rrb = n + 1;
	rt_b.ra = 0;
	rt_b.rra = 0;
	rt_b.rr = 0;
	rt_b.rrr = 0;
	return (rt_b);
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

int get_index_of_operation(int res[4])
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
	return (idx);
}

void	get_best_move(t_retations *operations, int len)
{
	// t_retations best_move;
	// int index; 
	int res[4]= {500};
	while (len > -1)
	{
		res[0] = operations[len].ra + operations[len].rb;
		res[1] = operations[len].ra + operations[len].rrb;
		res[2] = operations[len].rra + operations[len].rb;
		res[3] = operations[len].rra + operations[len].rrb;
		int idx = get_index_of_operation(res);
		if (idx == 0)
		{
			operations[len].rr = operations[len].rb;
			if (operations[len].ra < operations[len].rb)
				operations[len].rr = operations[len].ra;
			operations[len].ra -= operations[len].rr;
			operations[len].rb -= operations[len].rr;
			operations[len].rrb = 0;
			operations[len].rra = 0;
		}
		if (idx == 1)
		{
			operations[len].rb = 0;
			operations[len].rra = 0;
		}
		if (idx == 2)
		{
			operations[len].rrb = 0;
			operations[len].ra = 0;
		}
		if (idx == 3)
		{
			operations[len].rrr = operations[len].rrb;
			if (operations[len].rra < operations[len].rrb)
				operations[len].rrr = operations[len].rra;
			operations[len].rra -= operations[len].rrr;
			operations[len].rrb -= operations[len].rrr;
			operations[len].rb = 0;
			operations[len].ra = 0;
		}
		len--;
	}
}

t_retations	*get_all_iterations(t_stack *stack_a, t_stack *stack_b)
{
	int i = stack_a->top;
	t_retations tmp;
	t_retations *operations = malloc(sizeof(operations) * (i + 1));
	while (i > -1)
	{
		tmp = get_position_in_b(stack_b, stack_a->stack[i]);
		tmp.ra = stack_a->top - i;
		tmp.rra = i + 1;
		operations[i] = tmp;
		i--;
	}
	i = stack_a->top;
	while (i > -1)
	{
		ft_printf("value =\t%d\t{ ra =\t%d\t, rra =\t%d }\t{ rb =\t%d\t, rrb =\t%d }\n\n", stack_a->stack[i], operations[i].ra, operations[i].rra, operations[i].rb, operations[i].rrb);
		i--;
	}
	get_best_move(operations, stack_a->top);
	return (operations);
}
