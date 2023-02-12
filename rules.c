#include "push_swap.h"


void    ft_s(t_stack *stack)
{
    if (isEmpty(stack) || stack->capacity < 2)
        return ;
    int tmp, tmp2;
    tmp = pop(stack);
    tmp2 = pop(stack);
    push(stack, tmp);
    push(stack, tmp2);
}

void    ft_r(t_stack *stack)
{
    int first;

    if (isEmpty(stack) || stack->capacity < 2)
        return ;
    t_stack *tmp_arr = oncreate(stack->capacity - 1);
    first = pop(stack);
    while(!isEmpty(stack))
        push(tmp_arr, pop(stack));
    push(stack, first);
    while (!isEmpty(tmp_arr))
        push(stack, pop(tmp_arr));
    free(tmp_arr);
}

void    ft_rr(t_stack *stack)
{
    int last;

    if (isEmpty(stack))
        return ;
    t_stack *tmp_arr = oncreate(stack->capacity);
    while(!isEmpty(stack))
        push(tmp_arr, pop(stack));
    last = pop(tmp_arr);
    while (!isEmpty(tmp_arr))
        push(stack, pop(tmp_arr));
    push(stack, last);
    free(tmp_arr);
}

//TODO:
//  Push swap rules
//========================================
//  TODO:
//      sa (swap b): Swap the first 2 elements at the top of stack a.
//      Do nothing if there is only one or no elements.
void    sa(t_stack *stack_a)
{
    ft_s(stack_a);
    ft_printf("sa\n");
}

//  TODO:
//      sb (swap b): Swap the first 2 elements at the top of stack b.
//      Do nothing if there is only one or no elements.
void    sb(t_stack *stack_b)
{
    ft_s(stack_b);
    ft_printf("sb\n");
}


//  TODO:
//      ss : sa and sb at the same time.
void    ss(t_stack *stack_a, t_stack *stack_b)
{
    ft_s(stack_a);
    ft_s(stack_b);
    ft_printf("ss\n");
}

// TODO:
//      pa (push a): Take the first element at the top of b and put it at the top of a.
//      Do nothing if b is empty.
void    pa(t_stack *stack_a, t_stack *stack_b)
{
    if (isEmpty(stack_b))
        return ;
    push(stack_a, pop(stack_b));
    ft_printf("pa\n");
}

// TODO:
//      pb (push b): Take the first element at the top of a and put it at the top of b.
//      Do nothing if a is empty.
void    pb(t_stack *stack_b, t_stack *stack_a)
{
    if (isEmpty(stack_a))
        return ;
    push(stack_b, pop(stack_a));
    ft_printf("pb\n");
}

// TODO:
//      ra (rotate a): Shift up all elements of stack a by 1.
//      The first element becomes the last one.
void    ra(t_stack *stack_a)
{
    ft_r(stack_a);
    ft_printf("ra\n");
}

//  TODO:
//      rb (rotate b): Shift up all elements of stack b by 1.
//      The first element becomes the last one.
void    rb(t_stack *stack_b)
{
    ft_r(stack_b);
    ft_printf("rb\n");
}

//  TODO:
//      rr : ra and rb at the same time.
void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ft_r(stack_a);
    ft_r(stack_b);
    ft_printf("rr\n");
}

//  TODO:
//      rra (reverse rotate a): Shift down all elements of stack a by 1.
//      The last element becomes the first one.
void    rra(t_stack *stack_a)
{
    ft_rr(stack_a);
    ft_printf("rra\n");
}

//  TODO:
//      rrb (reverse rotate b): Shift down all elements of stack b by 1.
//      The last element becomes the first one.
void    rrb(t_stack *stack_b)
{
    ft_rr(stack_b);
    ft_printf("rrb\n");
}

//  TODO:
//      rrr : rra and rrb at the same time.
void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    ft_rr(stack_a);
    ft_rr(stack_b);
    ft_printf("rrr\n");
}

