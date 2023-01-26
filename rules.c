#include "push_swap.h"

//TODO:
//  Push swap rules
//========================================
//  TODO:
//      sa (swap b): Swap the first 2 elements at the top of stack a.
//      Do nothing if there is only one or no elements.
void    sa(t_stack *stack_a)
{
    if (isEmpty(stack_a))
        return ;
    int tmp;
    tmp = stack_a->stack[stack_a->top];
    stack_a->stack[stack_a->top] = stack_a->stack[stack_a->top - 1];
    stack_a->stack[stack_a->top - 1] = tmp;
}

//  TODO:
//      sb (swap b): Swap the first 2 elements at the top of stack b.
//      Do nothing if there is only one or no elements.
void    sb(t_stack *stack_b)
{
    sa(stack_b);
}


//  TODO:
//      ss : sa and sb at the same time.
void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sb(stack_a);
    sb(stack_b);
}

// TODO:
//      pa (push a): Take the first element at the top of b and put it at the top of a.
//      Do nothing if b is empty.
void    pa(t_stack *stack_a, t_stack *stack_b)
{
    if (isEmpty(stack_a))
        return ;
    push(stack_b, stack_a->stack[stack_a->top]);
    pop(stack_a);
}

// TODO:
//      pb (push b): Take the first element at the top of a and put it at the top of b.
//      Do nothing if a is empty.
void    pb(t_stack *stack_b, t_stack *stack_a)
{
    pa(stack_b, stack_a);
}

// TODO:
//      ra (rotate a): Shift up all elements of stack a by 1.
//      The first element becomes the last one.
void    ra(t_stack *stack_a)
{
    int first;
    int i;

    if (isEmpty(stack_a))
        return ;
    first = stack_a->stack[0];
    i = 0;
    while(i < stack_a->top)
    {
        stack_a->stack[i] = stack_a->stack[i + 1];
        i++;
    }
    stack_a->stack[i] = first;
}

//  TODO:
//      rb (rotate b): Shift up all elements of stack b by 1.
//      The first element becomes the last one.
void    rb(t_stack *stack_b)
{
    ra(stack_b);
}

//  TODO:
//      rr : ra and rb at the same time.
void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

//  TODO:
//      rra (reverse rotate a): Shift down all elements of stack a by 1.
//      The last element becomes the first one.
void    rra(t_stack *stack_a)
{
    int last;
    int i;

    if (isEmpty(stack_a))
        return ;
    last = stack_a->stack[stack_a->top];
    i = stack_a->top + 1;
    while(--i && i - 1 > -1)
        stack_a->stack[i] = stack_a->stack[i - 1];
    stack_a->stack[i] = last;
}

//  TODO:
//      rrb (reverse rotate b): Shift down all elements of stack b by 1.
//      The last element becomes the first one.
void    rrb(t_stack *stack_b)
{
    rra(stack_b);
}

//  TODO:
//      rrr : rra and rrb at the same time.
void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}

