/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:29:04 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 10:21:19 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	apply_rules_2(t_stack *stack_a, t_stack *stack_b, t_retations op)
{
	while (op.rrb)
	{
		rrb(stack_b);
		op.rrb--;
	}
	while (op.rr)
	{
		rr(stack_a, stack_b);
		op.rr--;
	}
	while (op.rrr)
	{
		rrr(stack_a, stack_b);
		op.rrr--;
	}
}

void	apply_rules(t_stack *stack_a, t_stack *stack_b, t_retations op)
{
	while (op.ra)
	{
		ra(stack_a);
		op.ra--;
	}
	while (op.rb)
	{
		rb(stack_b);
		op.rb--;
	}
	while (op.rra)
	{
		rra(stack_a);
		op.rra--;
	}
	apply_rules_2(stack_a, stack_b, op);
}
