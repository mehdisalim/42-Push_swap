/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:14:58 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 20:16:08 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static	void	conditions(t_stack **stack_a, t_stack **stack_b, char *buffer)
{
	if (!ft_strncmp(buffer, "pb\n", 3))
		pb(*stack_b, *stack_a, 0);
	else if (!ft_strncmp(buffer, "sa\n", 3))
		sa(*stack_a, 0);
	else if (!ft_strncmp(buffer, "sb\n", 3))
		sb(*stack_b, 0);
	else if (!ft_strncmp(buffer, "ss\n", 3))
		ss(*stack_a, *stack_b, 0);
	else if (!ft_strncmp(buffer, "ra\n", 3))
		ra(*stack_a, 0);
	else if (!ft_strncmp(buffer, "rb\n", 3))
		rb(*stack_b, 0);
	else if (!ft_strncmp(buffer, "rr\n", 3))
		rr(*stack_a, *stack_b, 0);
	else if (!ft_strncmp(buffer, "rra\n", 4))
		rra(*stack_a, 0);
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		rrb(*stack_b, 0);
	else if (!ft_strncmp(buffer, "rrr\n", 4))
		rrr(*stack_a, *stack_b, 0);
	else
	{
		free(buffer);
		destroy_program(*stack_a, *stack_b, 0);
	}
}

static	void	check_newline(t_stack **stack_a, t_stack **stack_b, char **str)
{
	if (ft_strchr(*str, '\n'))
	{
		if (!ft_strncmp(*str, "pa\n", 3))
			pa(*stack_a, *stack_b, 0);
		else
			conditions(stack_a, stack_b, *str);
		ft_bzero(*str, ft_strlen(*str));
	}
}

static	void	apply_input_rules(t_stack *stack_a, t_stack *stack_b)
{
	char	buffer[2];
	char	*str;
	char	*str2;
	int		reader;

	str = ft_calloc(1, sizeof(*str));
	while (1)
	{
		ft_bzero(buffer, 2);
		reader = read(0, buffer, 1);
		if (reader == -1 || !reader)
			break ;
		str2 = ft_strjoin(str, buffer);
		free(str);
		str = str2;
		check_newline(&stack_a, &stack_b, &str);
	}
	if (isasorted(stack_a) && is_empty(stack_b) && is_full(stack_a))
		ft_putendl_fd("\033[0;32mOK\033[0m", 1);
	else
		ft_putendl_fd("\033[0;31mKO\033[0m", 1);
	free(str);
}

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
		if ((number > 2147483647 || number < -2147483648) || !check)
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
	apply_input_rules(stack_a, stack_b);
	free(args);
	free_2d_array(numbers);
	free_stack(stack_a, stack_b);
	return (0);
}
