/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:24:44 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 15:39:30 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a, int show)
{
	ft_r(stack_a);
	if (show)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b, int show)
{
	ft_r(stack_b);
	if (show)
		ft_putendl_fd("rb", 1);
}

void	rra(t_stack *stack_a, int show)
{
	ft_rr(stack_a);
	if (show)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b, int show)
{
	ft_rr(stack_b);
	if (show)
		ft_putendl_fd("rrb", 1);
}
