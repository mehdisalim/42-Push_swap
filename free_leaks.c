/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:16:40 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 16:21:54 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_2d_array(char  **numbers)
{
    int i;

    i = -1;
    while (numbers[++i])
        free(numbers[i]);
    free(numbers);
}

void    free_stack(t_stack *stack_a, t_stack *stack_b)
{
    free(stack_b->stack);
    free(stack_a->stack);
    free(stack_b->tmp_arr);
    free(stack_a->tmp_arr);
    free(stack_b);
    free(stack_a);
}

