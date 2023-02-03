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

int	get_min_index(t_stack *stack)
{
	int i = stack->top;
	int lowest = stack->stack[i];
	int n = i;
	while (i > -1)
	{
		if (lowest < stack->stack[i])
		{
			lowest = stack->stack[i];
			n = i;
		}
		i--;
	}
	return (n);
}

t_retations get_position_in_b(t_stack *stack_b, int value)
{
	int pre_v = get_min_number(stack_b);
	
	t_retations rt_b;
	int i = stack_b->top;
	int *arr = stack_b->stack;
	int n = i;

	rt_b.rb = 0;
	rt_b.rrb = 0;
	rt_b.ra = 0;
	rt_b.rra = 0;
	rt_b.rr = 0;
	rt_b.rrr = 0;

	if (value < pre_v)
	{
		n = get_min_index(stack_b);
		rt_b.rb = stack_b->top - n;
		rt_b.rrb = n + 1;
		return (rt_b);
	}
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

int	*get_best_move(t_retations *operations, int len)
{
	// t_retations best_move;
	// int index;
	int res[4]= {0};
	int *arr = malloc(sizeof(int) * (len + 1));
	ft_memset(arr, 0, 4 * (len + 1));
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
	return (arr);
}

void	apply_rules(t_stack *stack_a, t_stack *stack_b, t_retations op)
{
	while (op.ra)
	{
		ra(stack_a, 0);
		op.ra--;
	}
	while (op.rb)
	{
		rb(stack_b, 0);
		op.rb--;
	}
	while (op.rra)
	{
		rra(stack_a, 0);
		op.rra--;
	}
	while (op.rrb)
	{
		rrb(stack_b, 0);
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

void	push_to_b(t_stack *stack_a, t_stack *stack_b, t_retations *operations, int *arr)
{
	int idx = get_index_of_operation(arr, stack_a->top);
	t_retations op = operations[idx];
	apply_rules(stack_a, stack_b, op);
	pb(stack_b, stack_a);
}

t_retations	*get_all_iterations(t_stack *stack_b, int *value, int top)
{
	int i = top;
	t_retations tmp;
	t_retations *operations = malloc(sizeof(operations) * (i + 1));
	while (i > -1)
	{
		tmp = get_position_in_b(stack_b, value[i]);
		tmp.ra = top - i;
		tmp.rra = i + 1;
		operations[i] = tmp;
		i--;
	}
	return (operations);
}


// void	sort_stack_b(t_stack *stack_b)
// {
// 	int idx = get_min_index(stack_b);
// 	while (!isbsorted(stack_b))
// 	{
// 		if (idx < stack_b->top / 2)
// 			rrb(stack_b, 0);
// 		else
// 			rb(stack_b, 0);
// 	}
// }

void	push_all(t_stack *stack_a, t_stack *stack_b)
{
	int *arr;
	t_retations *operations;
	while (stack_a->top > -1)
	{
		operations = get_all_iterations(stack_b, stack_a->stack, stack_a->top);
		arr = get_best_move(operations, stack_a->top);
		push_to_b(stack_a, stack_b, operations, arr);
	}
	// sort_stack_b(stack_b);
}
