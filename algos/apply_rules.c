/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:29:04 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 19:58:44 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	apply_rules_2(t_stack *stack_a, t_stack *stack_b, t_retations op)
{
	while (op.rrb)
	{
		rrb(stack_b, 1);
		op.rrb--;
	}
	while (op.rr)
	{
		rr(stack_a, stack_b, 1);
		op.rr--;
	}
	while (op.rrr)
	{
		rrr(stack_a, stack_b, 1);
		op.rrr--;
	}
}

void	apply_rules(t_stack *stack_a, t_stack *stack_b, t_retations op)
{
	while (op.ra)
	{
		ra(stack_a, 1);
		op.ra--;
	}
	while (op.rb)
	{
		rb(stack_b, 1);
		op.rb--;
	}
	while (op.rra)
	{
		rra(stack_a, 1);
		op.rra--;
	}
	apply_rules_2(stack_a, stack_b, op);
}
