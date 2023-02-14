/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:24:44 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 19:26:12 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ra(t_stack *stack_a)
{
    ft_r(stack_a);
    ft_printf("ra\n");
}

void    rb(t_stack *stack_b)
{
    ft_r(stack_b);
    ft_printf("rb\n");
}

void    rra(t_stack *stack_a)
{
    ft_rr(stack_a);
    ft_printf("rra\n");
}

void    rrb(t_stack *stack_b)
{
    ft_rr(stack_b);
    ft_printf("rrb\n");
}
