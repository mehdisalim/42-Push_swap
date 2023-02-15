/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:13:53 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 10:45:22 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "structs.h"

//  DESTROY_PROGRAM.C
void		free_stack(t_stack *stack_a, t_stack *stack_b);
void		free_2d_array(char **numbers);
void		destroy_program(t_stack *stack_a, t_stack *stack_b, char **numbers);

//  ALGOS/APPLY_RULES.C
void		apply_rules(t_stack *stack_a, t_stack *stack_b, t_retations op);

//  UTILS/UTILS_CHECKING_ARGS.C
int			check_isdigits(char *str);
int			get_num_count(char **num);
char		*get_all_args(int ac, char **av);
int			check_is_duplicated(t_stack *stack);

//  PUSH SWAP UTILS
int			get_max_number(t_stack *stack, int *index);
int			get_min_number(t_stack *stack, int *index);
int			get_index_of_operation(int *res, int len);
int			get_number_of_operation(int res[4], int *index);
t_retations	get_position_in_a(t_stack *stack_b, int value);

//  UTILS/UTILS_SORT.C
void		sort_stack_a(t_stack *stack_a);
int			isasorted(t_stack *stack_a);
void		detect_sort(t_stack *stack_a, t_stack *stack_b);
void		sort_four_conditions(t_stack *stack_a, t_stack *stack_b, int idx);
void		sort_five_conditions(t_stack *stack_a, t_stack *stack_b, int idx);

//  SORT.C
void		sort_two(t_stack *stack_a);
void		sort_three(t_stack *stack_a);
void		sort_four(t_stack *stack_a, t_stack *stack_b);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		sort_all(t_stack *stack_a, t_stack *stack_b);

//  ALGOS/BEST_MOVE.C
void		best_move(t_stack *stack_a, t_stack *stack_b);

//  ALGOS/CHUNK_ALGO.C
void		chunck_algo(t_stack *stack_a, t_stack *stack_b);

//  STACK IMPLIMENTATION STACK.C
t_stack		*oncreate(int capacity);
void		push(t_stack *stack, int content);
int			pop(t_stack *stack);
int			is_empty(t_stack *stack);

//  RULES/*.c
void		ft_r(t_stack *stack);
void		ft_rr(t_stack *stack);
void		ft_s(t_stack *stack);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_b, t_stack *stack_a);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

#endif
