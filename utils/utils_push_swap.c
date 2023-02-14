/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:08:59 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 19:09:00 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_number(t_stack *stack, int *index)
{
	int i = stack->top;
	int lowest = stack->stack[i];
	int n = i;
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
	int i = stack->top;
	int bigest = stack->stack[i];
	int n = i;
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

int get_number_of_operation(int res[4], int *index)
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
	*index = idx;
	return (small);
}