/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:08:21 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 10:21:19 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_copy(int *dest, int *src, int len)
{
	int	i;

	i = -1;
	while (++i <= len)
		dest[i] = src[i];
}

static int	get_middle_of_arr(t_stack *stack_a, int *tmp)
{
	int	value;
	int	i;

	value = 0;
	i = -1;
	while (++i <= stack_a->top)
	{
		if (i + 1 <= stack_a->top && tmp[i] > tmp[i + 1])
		{
			value = tmp[i];
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = value;
			i = -1;
		}
	}
	value = tmp[i / 2];
	return (value);
}

static int	get_less_than_middle(t_stack *stack_a, int value)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->stack[i] < value)
			res++;
		i++;
	}
	return (res);
}

void	chunck_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	middle;
	int	res;

	middle = 0;
	res = 0;
	while (stack_a->top > 2)
	{
		if (res == 0)
		{
			ft_copy(stack_a->tmp_arr, stack_a->stack, stack_a->top);
			middle = get_middle_of_arr(stack_a, stack_a->tmp_arr);
			res = get_less_than_middle(stack_a, middle);
		}
		if (stack_a->stack[stack_a->top] <= middle)
		{
			pb(stack_b, stack_a);
			res--;
		}
		else
			ra(stack_a);
	}
	if (stack_a->top == 2)
		sort_three(stack_a);
}
