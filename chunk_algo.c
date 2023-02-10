#include "push_swap.h"

int	get_min_index(t_stack *stack)
{
	int i = stack->top;
	int lowest = stack->stack[i];
	int n = i;
	while (i > -1)
	{
		if (lowest > stack->stack[i])
		{
			lowest = stack->stack[i];
			n = i;
		}
		i--;
	}
	return (n);
}

void divide_array(int *arr, int len)
{
	int divider = 20;
	(void)arr;
	while (len <= divider || len % divider != 0)
		divider--;
	int *divide_idx = malloc(sizeof(int) * divider);
	int increements = len / divider;
	int i = 0;
	int j = -1;
	while (i < len)
	{
		divide_idx[++j] = arr[i];
		i += increements;
		
	}
	i = -1;
	while (++i < j)
		ft_printf("%d\n", divide_idx[i]);
}

int	*quick_sort(t_stack *stack_a)
{
    t_stack *tmp = stack_a;
    int idx;
    int value;
    int *arr = malloc(sizeof(int) * tmp->capacity);
    int i = 0;
    while (tmp->top > -1)
    {
        idx = get_min_index(tmp);
        value = tmp->stack[idx];
        tmp->stack[idx] = tmp->stack[tmp->top]; 
        tmp->stack[tmp->top] = value;
        arr[i++] = pop(tmp);
    }
	divide_array(arr, i);
	return (arr);
}


// void    chunk_algo(t_stack *stack_a, t_stack *stack_b)
// {

// }