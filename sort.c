/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:12:23 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 10:53:36 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->stack[0] < stack_a->stack[1])
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	*arr;

	arr = stack_a->stack;
	if (arr[2] > arr[1] && arr[0] > arr[1] && arr[2] < arr[0])
		sa(stack_a);
	if (arr[2] > arr[1] && arr[1] > arr[0])
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (arr[2] > arr[1] && arr[0] > arr[1] && arr[2] > arr[0])
		ra(stack_a);
	if (arr[2] < arr[1] && arr[0] < arr[1] && arr[2] < arr[0])
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (arr[2] < arr[1] && arr[0] < arr[1] && arr[2] > arr[0])
		rra(stack_a);
	return ;
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	idx;

	if (isasorted(stack_a))
		return ;
	get_min_number(stack_a, &idx);
	sort_four_conditions(stack_a, stack_b, idx);
	sort_three(stack_a);
	while (stack_b->top > -1)
		pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	idx;

	if (isasorted(stack_a))
		return ;
	get_min_number(stack_a, &idx);
	sort_five_conditions(stack_a, stack_b, idx);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_all(t_stack *stack_a, t_stack *stack_b)
{
	chunck_algo(stack_a, stack_b);
	sort_three(stack_a);
	best_move(stack_a, stack_b);
	sort_stack_a(stack_a);
}
