/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:13:53 by esalim            #+#    #+#             */
/*   Updated: 2023/01/26 12:42:52 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
    int     top;
    int     capacity;
    int    *stack;
}   t_stack;

//  PUSH SWAP UTILS
int     check_isdigits(char *str);
int     get_num_count(char   **num);
void    ft_swap(char   **str1, char **str2);
char    *get_all_args(int ac, char **av);


//  STACK IMPLIMENTATION
t_stack *oncreate(int capacity);
int     isFull(t_stack *stack);
int     isEmpty(t_stack *stack);
void    push(t_stack *stack, int content);
void    pop(t_stack *stack);
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
