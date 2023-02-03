/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:13:53 by esalim            #+#    #+#             */
/*   Updated: 2023/02/03 09:59:47 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_retations
{
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
} t_retations;

typedef struct s_stack
{
    int     top;
    int     capacity;
    int     *stack;
}   t_stack;

//  PUSH SWAP UTILS
int     check_isdigits(char *str);
int     get_num_count(char   **num);
void    ft_swap(char   **str1, char **str2);
char    *get_all_args(int ac, char **av);

void    detect_sort(t_stack *stack_a, t_stack *stack_b, int *iter);
int     isbsorted(t_stack *stack_b);
void    sort_two(t_stack *stack_a);
void    sort_three(t_stack *stack_a);
void    sort_four(t_stack *stack_a, t_stack *stack_b);
void    sort_five(t_stack *stack_a, t_stack *stack_b);
void    sort_all(t_stack *stack_a, t_stack *stack_b, int* iter);
int     best_move(t_stack *stack_a, t_stack *stack_b);
int     how_many_iteration_in_b(t_stack *stack_b, int value);
t_retations get_position_in_b(t_stack *stack_b, int value);
void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b);

//  STACK IMPLIMENTATION
t_stack *oncreate(int capacity);
int     isFull(t_stack *stack);
int     isEmpty(t_stack *stack);
void    push(t_stack *stack, int content);
int     pop(t_stack *stack);
void    clear(t_stack *stack);

//  PUSH SWAP RULES
void    sa(t_stack *stack_a, int issb);
void    sb(t_stack *stack_b, int isss);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b, int ispb);
void    pb(t_stack *stack_b, t_stack *stack_a);
void    ra(t_stack *stack_a, int isra);
void    rb(t_stack *stack_b, int isrr);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a, int isrra);
void    rrb(t_stack *stack_b, int isrrr);
void    rrr(t_stack *stack_a, t_stack *stack_b);

#endif
