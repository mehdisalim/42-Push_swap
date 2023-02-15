/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:22:41 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 17:11:21 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_2d_array(char **numbers)
{
	int	i;

	i = -1;
	while (numbers[++i])
		free(numbers[i]);
	free(numbers);
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack)
		free(stack_a->stack);
	if (stack_b->stack)
		free(stack_b->stack);
	if (stack_b->tmp_arr)
		free(stack_b->tmp_arr);
	if (stack_a->tmp_arr)
		free(stack_a->tmp_arr);
	if (stack_b)
		free(stack_b);
	if (stack_a)
		free(stack_a);
}

void	destroy_program(t_stack *stack_a, t_stack *stack_b, char **numbers)
{
	if (stack_a && stack_b)
		free_stack(stack_a, stack_b);
	if (numbers)
		free_2d_array(numbers);
	ft_putendl_fd("Error", 2);
	exit(1);
}
