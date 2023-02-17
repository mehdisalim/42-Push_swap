/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:27:44 by esalim            #+#    #+#             */
/*   Updated: 2023/02/17 10:55:36 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	setup_stack(t_stack **s_a, t_stack **s_b, char **num, int cp)
{
	int		i;
	int		check;
	long	number;

	*s_a = oncreate(cp);
	*s_b = oncreate(cp);
	if (!*s_a || !*s_b)
		destroy_program(*s_a, *s_b, num);
	i = cp;
	while (--i > -1)
	{
		check = check_isdigits(num[i]);
		number = ft_atoi(num[i]);
		if ((number > 2147483647 || number < -2147483648)
			|| !check || ft_strlen(num[i]) > 12)
			destroy_program(*s_a, *s_b, num);
		push(*s_a, number);
	}
}

int	main(int ac, char **av)
{
	char	*args;
	char	**numbers;
	int		capacity;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	args = get_all_args(ac, av);
	numbers = ft_split(args, ' ');
	capacity = get_num_count(numbers);
	stack_a = 0;
	stack_b = 0;
	setup_stack(&stack_a, &stack_b, numbers, capacity);
	if (check_is_duplicated(stack_a))
		destroy_program(stack_a, stack_b, numbers);
	if (!isasorted(stack_a))
		detect_sort(stack_a, stack_b);
	free(args);
	free_2d_array(numbers);
	free_stack(stack_a, stack_b);
	return (0);
}
