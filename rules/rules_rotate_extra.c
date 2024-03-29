/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:24:44 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 15:38:19 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_r(t_stack *stack)
{
	int	first;
	int	len;

	len = 0;
	if (is_empty(stack) || stack->capacity < 2)
		return ;
	ft_bzero(stack->tmp_arr, stack->capacity);
	first = pop(stack);
	while (stack->top > -1)
		stack->tmp_arr[len++] = pop(stack);
	push(stack, first);
	while (--len > -1)
		push(stack, stack->tmp_arr[len]);
}

void	ft_rr(t_stack *stack)
{
	int	last;
	int	len;

	len = 0;
	if (is_empty(stack))
		return ;
	ft_bzero(stack->tmp_arr, stack->capacity);
	while (stack->top > 0)
		stack->tmp_arr[len++] = pop(stack);
	last = pop(stack);
	while (--len > -1)
		push(stack, stack->tmp_arr[len]);
	push(stack, last);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int show)
{
	ft_r(stack_a);
	ft_r(stack_b);
	if (show)
		ft_putendl_fd("rr", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int show)
{
	ft_rr(stack_a);
	ft_rr(stack_b);
	if (show)
		ft_putendl_fd("rrr", 1);
}
