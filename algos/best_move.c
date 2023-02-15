/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:08:15 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 10:29:10 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_right_operations(t_retations **operations, int idx, int len)
{
	if (idx == 1)
	{
		(*operations)[len].rb = 0;
		(*operations)[len].rra = 0;
	}
	else if (idx == 2)
	{
		(*operations)[len].rrb = 0;
		(*operations)[len].ra = 0;
	}
	else if (idx == 3)
	{
		(*operations)[len].rrr = (*operations)[len].rrb;
		if ((*operations)[len].rra < (*operations)[len].rrb)
				(*operations)[len].rrr = (*operations)[len].rra;
		(*operations)[len].rra -= (*operations)[len].rrr;
		(*operations)[len].rrb -= (*operations)[len].rrr;
		(*operations)[len].rb = 0;
		(*operations)[len].ra = 0;
	}
}

static void	get_best_move(t_retations *operations, int len, int *arr)
{
	int	res[4];
	int	idx;

	ft_bzero(res, sizeof(int) * 4);
	while (len > -1)
	{
		idx = 0;
		res[0] = operations[len].ra + operations[len].rb;
		res[1] = operations[len].ra + operations[len].rrb;
		res[2] = operations[len].rra + operations[len].rb;
		res[3] = operations[len].rra + operations[len].rrb;
		arr[len] = get_number_of_operation(res, &idx);
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
		get_right_operations(&operations, idx, len);
		len--;
	}
}

static void	push_to_a(t_stack *s_a, t_stack *s_b, t_retations *oper, int *arr)
{
	t_retations	op;
	int			idx;

	idx = get_index_of_operation(arr, s_b->top);
	op = oper[idx];
	apply_rules(s_a, s_b, op);
	pa(s_a, s_b);
}

static void	get_all_iterations(t_stack *s_a, int *vl, int top, t_retations *op)
{
	t_retations	tmp;
	int			i;

	i = top;
	while (i > -1)
	{
		tmp = get_position_in_a(s_a, vl[i]);
		tmp.rb = top - i;
		tmp.rrb = i + 1;
		op[i] = tmp;
		i--;
	}
}

void	best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_retations	*operations;
	int			*arr;

	arr = ft_calloc(stack_b->top + 1, sizeof(int));
	operations = ft_calloc(5, sizeof(t_retations));
	if (!arr || !operations)
		destroy_program(stack_a, stack_b, NULL);
	while (stack_b->top > -1)
	{
		get_all_iterations(stack_a, stack_b->stack, stack_b->top, operations);
		get_best_move(operations, stack_b->top, arr);
		push_to_a(stack_a, stack_b, operations, arr);
	}
	free(operations);
	free(arr);
}
