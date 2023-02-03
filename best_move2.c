#include "push_swap.h"

int	get_max_number(t_stack *stack)
{
	int i = stack->top;
	int bigest = stack->stack[i];
	while (i > -1)
	{
		if (bigest < stack->stack[i])
			bigest = stack->stack[i];
		i--;
	}
	return (bigest);
}

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
	return (rt_b);
}

// t_retations getpositions_in_a(t_stack *stack_a)
// {
// 	t_retations rt_a;
// 	int *arr = stack_a->stack;
// 	int top = stack_a->top;
// 	while (top)
// 	{
		
// 	}
// 	rt_a.ra = 0;
// 	rt_a.rb = stack_a->top - n;
// 	rt_a.rr = 0;
// 	rt_a.rra = 0;
// 	rt_a.rrb = n + 1;
// 	rt_a.rrr = 0;
// }

// void	compare_operations(t_stack *stack_a, t_stack *stack_b)
// {

// }

void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	// pb(stack_b, stack_a);
	// pb(stack_b, stack_a);
	// if (stack_b->stack[0] > stack_b->stack[1])
	// 	sb(stack_b, 0);
	int i = stack_a->top;
	t_retations tmp;
	int j = 0;
	t_retations *operations = malloc(sizeof(operations) * (i + 1));
	while (i > -1)
	{
		// rev_sorted_b(stack_b);
		tmp = get_position_in_b(stack_b, stack_a->stack[i]);
		tmp.ra = stack_a->top - i;
		tmp.rra = i + 1;
		operations[i] = tmp;
		j++;
		// ft_printf("stack_a value\t=\t%d\trb\t=\t%d\t|\trrb\t=\t%d\n", stack_a->stack[i], n.rb, n.rrb);
		// while (n.rb)
		// {
		// 	rb(stack_b, 0);
		// 	n.rb--;
		// }
		// while (n.rrb)
		// {
		// 	rrb(stack_b, 0);
		// 	n.rrb--;
		// }
		// pb(stack_b, stack_a);
		i--;
	}
	i = stack_a->top;
	while (i > -1)
	{
		ft_printf("value =\t%d\t{ ra =\t%d\t, rra =\t%d }\t{ rb =\t%d\t, rrb =\t%d }\n", stack_a->stack[i], operations[i].ra, operations[i].rra, operations[i].rb, operations[i].rrb);
		i--;
	}

	
}