#include "push_swap.h"

t_retations	get_position_in_a(t_stack *stack_a, int value)
{
	int n;
	int next_v;
	
	t_retations rt_a;
	int i = stack_a->top;
	int *arr = stack_a->stack;

	rt_a.rb = 0;
	rt_a.rrb = 0;
	rt_a.ra = 0;
	rt_a.rra = 0;
	rt_a.rr = 0;
	rt_a.rrr = 0;

	if (value < get_min_number(stack_a, &n))
	{
		rt_a.ra = stack_a->top - n;
		rt_a.rra = n + 1;
		return (rt_a);
	}
	next_v = get_max_number(stack_a, &n);
	if (value > next_v)
	{
		rt_a.ra = stack_a->top - n;
		rt_a.rra = n + 1;
		return (rt_a);
	}
	while (i > -1)
	{
		if (next_v >= arr[i] && arr[i] > value)
		{
			next_v = arr[i];
			n = i;
		}
		i--;
	}
	rt_a.ra = stack_a->top - n;
	rt_a.rra = n + 1;
	return (rt_a);
}

void	get_best_move(t_retations *operations, int len, int *arr)
{
	// t_retations best_move;
	// int index;
	int res[4]= {0};
	while (len > -1)
	{
		res[0] = operations[len].ra + operations[len].rb;
		res[1] = operations[len].ra + operations[len].rrb;
		res[2] = operations[len].rra + operations[len].rb;
		res[3] = operations[len].rra + operations[len].rrb;
		arr[len] = get_number_of_operation(res);
		int idx = get_index_of_operation(res, 3);
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

void	apply_rules(t_stack *stack_a, t_stack *stack_b, t_retations op)
{
	while (op.ra)
	{
		ra(stack_a);
		op.ra--;
	}
	while (op.rb)
	{
		rb(stack_b);
		op.rb--;
	}
	while (op.rra)
	{
		rra(stack_a);
		op.rra--;
	}
	while (op.rrb)
	{
		rrb(stack_b);
		op.rrb--;
	}
	while (op.rr)
	{
		rr(stack_a, stack_b);
		op.rr--;
	}
	while (op.rrr)
	{
		rrr(stack_a, stack_b);
		op.rrr--;
	}
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b, t_retations *operations, int *arr)
{
	int idx = get_index_of_operation(arr, stack_b->top);
	t_retations op = operations[idx];
	apply_rules(stack_a, stack_b, op);
	pa(stack_a, stack_b);
}

void	get_all_iterations(t_stack *stack_a, int *value, int top, t_retations *operations)
{
	int i = top;
	t_retations tmp;
	while (i > -1)
	{
		tmp = get_position_in_a(stack_a, value[i]);
		tmp.rb = top - i;
		tmp.rrb = i + 1;
		operations[i] = tmp;
		i--;
	}
}


void	push_all(t_stack *stack_a, t_stack *stack_b)
{
	int *arr = ft_calloc(stack_b->top + 1, sizeof(int));
	t_retations *operations = ft_calloc(5, sizeof(t_retations));
	while (stack_b->top > -1)
	{
		get_all_iterations(stack_a, stack_b->stack, stack_b->top, operations);
		get_best_move(operations, stack_b->top, arr);
		push_to_a(stack_a, stack_b, operations, arr);
	}
	// free(operations);
	// free(arr);
}
