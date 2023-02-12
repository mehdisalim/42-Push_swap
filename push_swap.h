/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:13:53 by esalim            #+#    #+#             */
/*   Updated: 2023/02/12 17:35:01 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"


#define FT_P(msg) ft_printf(#msg " ==> %d\n", msg)

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

void    print_stack(t_stack *stack);

//  PUSH SWAP UTILS
int     check_isdigits(char *str);
int     get_num_count(char   **num);
void    ft_swap(char   **str1, char **str2);
char    *get_all_args(int ac, char **av);
void	ft_copy(t_stack *tmp, t_stack *src);
int	    get_max_number(t_stack *stack, int *index);
int	    get_min_number(t_stack *stack, int *index);
int     get_index_of_operation(int *res, int len);
int     get_number_of_operation(int res[4]);

void	sort_stack_a(t_stack *stack_a);
void    detect_sort(t_stack *stack_a, t_stack *stack_b);
int     isbsorted(t_stack *stack_b);
int     isasorted(t_stack *stack_a);
void    sort_two(t_stack *stack_a);
void    sort_three(t_stack *stack_a);
void    sort_four(t_stack *stack_a, t_stack *stack_b);
void    sort_five(t_stack *stack_a, t_stack *stack_b);
void    sort_all(t_stack *stack_a, t_stack *stack_b);
int     best_move(t_stack *stack_a, t_stack *stack_b);
int     how_many_iteration_in_b(t_stack *stack_b, int value);
t_retations get_position_in_a(t_stack *stack_b, int value);
void    get_all_iterations(t_stack *stack_b, int *value, int top, t_retations *operations);
void	push_all(t_stack *stack_a, t_stack *stack_b);
int	    get_min_index(t_stack *stack);
int	    get_middle_of_arr(t_stack *stack_a);
void	chunck_algo(t_stack *stack_a, t_stack *stack_b);


//  STACK IMPLIMENTATION
t_stack *oncreate(int capacity);
int     isFull(t_stack *stack);
int     isEmpty(t_stack *stack);
void    push(t_stack *stack, int content);
int     pop(t_stack *stack);
void    clear(t_stack *stack);

//  PUSH SWAP RULES
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_b, t_stack *stack_a);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

#endif
