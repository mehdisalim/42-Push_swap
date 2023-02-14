/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:51:58 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 23:53:39 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*oncreate(int capacity)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (0);
	stack->capacity = capacity;
	stack->top = -1;
	stack->stack = ft_calloc(capacity, sizeof(int));
	stack->tmp_arr = ft_calloc(stack->capacity, sizeof(int));
	if (!stack->stack || !stack->tmp_arr)
		return (0);
	return (stack);
}

int	is_full(t_stack *stack)
{
	if (stack->top >= stack->capacity)
		return (1);
	return (0);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

void	push(t_stack *stack, int content)
{
	if (is_full(stack) || !stack->stack)
		return ;
	stack->stack[++stack->top] = content;
}

int	pop(t_stack *stack)
{
	int	value;

	if (is_empty(stack) || !stack->stack)
		return (0);
	value = stack->stack[stack->top];
	stack->stack[stack->top] = 0;
	stack->top--;
	return (value);
}
