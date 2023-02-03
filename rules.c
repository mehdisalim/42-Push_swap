#include "push_swap.h"

//TODO:
//  Push swap rules
//========================================
//  TODO:
//      sa (swap b): Swap the first 2 elements at the top of stack a.
//      Do nothing if there is only one or no elements.
void    sa(t_stack *stack_a, int issb)
{
    if (isEmpty(stack_a) || stack_a->capacity < 2)
        return ;
    int tmp, tmp2;
    tmp = pop(stack_a);
    tmp2 = pop(stack_a);
    push(stack_a, tmp);
    push(stack_a, tmp2);
    if (!issb)
        ft_printf("sa\n");
}

//  TODO:
//      sb (swap b): Swap the first 2 elements at the top of stack b.
//      Do nothing if there is only one or no elements.
void    sb(t_stack *stack_b, int isss)
{
    sa(stack_b, 1);
    if (!isss)
        ft_printf("sb\n");
}


//  TODO:
//      ss : sa and sb at the same time.
void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a, 0);
    sb(stack_b, 1);
    ft_printf("ss\n");
}

// TODO:
//      pa (push a): Take the first element at the top of b and put it at the top of a.
//      Do nothing if b is empty.
void    pa(t_stack *stack_a, t_stack *stack_b, int ispb)
{
    if (isEmpty(stack_b))
        return ;
    push(stack_a, pop(stack_b));
    if (!ispb)
        ft_printf("pa\n");
}

// TODO:
//      pb (push b): Take the first element at the top of a and put it at the top of b.
//      Do nothing if a is empty.
void    pb(t_stack *stack_b, t_stack *stack_a)
{
    pa(stack_b, stack_a, 1);
    ft_printf("pb\n");
}

// TODO:
//      ra (rotate a): Shift up all elements of stack a by 1.
//      The first element becomes the last one.
void    ra(t_stack *stack_a, int isrb)
{
    int first;

    if (isEmpty(stack_a) || stack_a->capacity < 2)
        return ;
    t_stack *tmp_arr = oncreate(stack_a->capacity - 1);
    first = pop(stack_a);
    while(!isEmpty(stack_a))
        push(tmp_arr, pop(stack_a));
    push(stack_a, first);
    while (!isEmpty(tmp_arr))
        push(stack_a, pop(tmp_arr));
    free(tmp_arr);
    if (!isrb)
        ft_printf("ra\n");
}

//  TODO:
//      rb (rotate b): Shift up all elements of stack b by 1.
//      The first element becomes the last one.
void    rb(t_stack *stack_b, int isrr)
{
    ra(stack_b, 1);
    if (!isrr)
        ft_printf("rb\n");
}

//  TODO:
//      rr : ra and rb at the same time.
void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a, 1);
    rb(stack_b, 1);
    ft_printf("rr\n");
}

//  TODO:
//      rra (reverse rotate a): Shift down all elements of stack a by 1.
//      The last element becomes the first one.
void    rra(t_stack *stack_a, int isrrb)
{
    int last;

    if (isEmpty(stack_a))
        return ;
    t_stack *tmp_arr = oncreate(stack_a->capacity);
    while(!isEmpty(stack_a))
        push(tmp_arr, pop(stack_a));
    last = pop(tmp_arr);
    while (!isEmpty(tmp_arr))
        push(stack_a, pop(tmp_arr));
    push(stack_a, last);
    free(tmp_arr);
    if (!isrrb)
        ft_printf("rra\n");
}

//  TODO:
//      rrb (reverse rotate b): Shift down all elements of stack b by 1.
//      The last element becomes the first one.
void    rrb(t_stack *stack_b, int isrrr)
{
    rra(stack_b, 1);
    if (!isrrr)
        ft_printf("rrb\n");
}
//  TODO:
//      rrr : rra and rrb at the same time.
void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a, 1);
    rrb(stack_b, 1);
    ft_printf("rrr\n");
}

