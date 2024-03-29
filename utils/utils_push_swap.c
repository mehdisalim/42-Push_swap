/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:08:59 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 11:17:24 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_number(t_stack *stack, int *index)
{
	int	lowest;
	int	i;
	int	n;

	i = stack->top;
	lowest = stack->stack[i];
	n = i;
	while (i > -1)
	{
		if (lowest > stack->stack[i])
		{
			lowest = stack->stack[i];
			n = i;
		}
		i--;
	}
	*index = n;
	return (lowest);
}

int	get_max_number(t_stack *stack, int *index)
{
	int	bigest;
	int	i;
	int	n;

	i = stack->top;
	bigest = stack->stack[i];
	n = i;
	while (i > -1)
	{
		if (bigest < stack->stack[i])
		{
			bigest = stack->stack[i];
			n = i;
		}
		i--;
	}
	*index = n;
	return (bigest);
}

int	get_index_of_operation(int *res, int len)
{
	int	small;
	int	idx;
	int	i;

	small = res[0];
	idx = 0;
	i = 0;
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

int	get_number_of_operation(int res[4], int *index)
{
	int	small;
	int	idx;
	int	i;

	small = res[0];
	idx = 0;
	i = 0;
	while (i < 4)
	{
		if (res[i] <= small)
		{
			small = res[i];
			idx = i;
		}
		i++;
	}
	*index = idx;
	return (small);
}

t_retations	get_position_in_a(t_stack *stack_a, int value)
{
	t_retations	rt_a;
	int			next_v;
	int			*arr;
	int			n;
	int			i;

	i = stack_a->top + 1;
	arr = stack_a->stack;
	ft_bzero(&rt_a, (sizeof rt_a));
	next_v = get_max_number(stack_a, &n);
	if (value >= get_min_number(stack_a, &n) && value <= next_v)
	{
		while (--i > -1)
		{
			if (next_v >= arr[i] && arr[i] > value)
			{
				next_v = arr[i];
				n = i;
			}
		}
	}
	rt_a.ra = stack_a->top - n;
	rt_a.rra = n + 1;
	return (rt_a);
}
