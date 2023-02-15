/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:34:20 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 15:44:40 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	isasorted(t_stack *stack_a)
{
	int	*arr;
	int	i;

	arr = stack_a->stack;
	i = 0;
	while (i < stack_a->top)
	{
		if (i + 1 <= stack_a->top && arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_stack_a(t_stack *stack_a)
{
	int	idx;
	int	test;

	idx = 0;
	get_min_number(stack_a, &idx);
	if (idx < stack_a->top / 2)
	{
		idx++;
		while (idx--)
			rra(stack_a, 1);;
	}
	else
	{
		test = stack_a->top - idx;
		while (test--)
			ra(stack_a, 1);;
	}
}

void	sort_four_conditions(t_stack *stack_a, t_stack *stack_b, int idx)
{
	if (idx == stack_a->top)
		pb(stack_b, stack_a, 1);
	else if (idx == 0)
	{
		rra(stack_a, 1);;
		pb(stack_b, stack_a, 1);
	}
	else if (idx == 1)
	{
		rra(stack_a, 1);;
		rra(stack_a, 1);;
		pb(stack_b, stack_a, 1);
	}
	else if (idx == 2)
	{
		sa(stack_a, 1);
		pb(stack_b, stack_a, 1);
	}
}

void	sort_five_conditions(t_stack *stack_a, t_stack *stack_b, int idx)
{
	if (idx == stack_a->top)
		pb(stack_b, stack_a, 1);
	else if (idx == 0)
	{
		rra(stack_a, 1);;
		pb(stack_b, stack_a, 1);
	}
	else if (idx == 1)
	{
		rra(stack_a, 1);;
		rra(stack_a, 1);;
		pb(stack_b, stack_a, 1);
	}
	else if (idx == 2)
	{
		ra(stack_a, 1);;
		sa(stack_a, 1);
		pb(stack_b, stack_a, 1);
	}
	else if (idx == 3)
	{
		sa(stack_a, 1);
		pb(stack_b, stack_a, 1);
	}
}

void	detect_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->capacity == 2)
		sort_two(stack_a);
	else if (stack_a->capacity == 3)
		sort_three(stack_a);
	else if (stack_a->capacity == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->capacity == 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->capacity > 5)
		sort_all(stack_a, stack_b);
}
