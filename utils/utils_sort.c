/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:34:20 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 23:46:40 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			rra(stack_a);
	}
	else
	{
		test = stack_a->top - idx;
		while (test--)
			ra(stack_a);
	}
}
