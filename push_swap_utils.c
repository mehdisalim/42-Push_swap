#include "push_swap.h"

int check_isdigits(char *str)
{
    int i;
	
	i = 0;
	if (str[i] == '+' || str[i] == '-')
            i++;
	if (!str[i])
		return (0);
    while (str[i])
        if (ft_isdigit(str[i++]) == 0)
            return (0);
    return (1);
}

int get_num_count(char   **num)
{
    int i = -1;
    while (num[++i]);
    return (i);
}


size_t	my_strlcat(char *dst, const char *src, size_t n)
{
	size_t	j;
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	j = 0;
	i = 0;
	srclen = ft_strlen((char *)src);
	if ((dst || src) && !n)
		return (srclen);
	destlen = ft_strlen((char *)dst);
	if (destlen >= n || !n)
		return (n + srclen);
	while (dst[j])
		j++;
	dst[j++] = ' ';
	while (src[i] && j + 1 < n)
		dst[j++] = src[i++];
	dst[j] = 0;
	return (srclen + destlen);
}

char    *get_all_args(int ac, char **av)
{
    char    *res;
    int     i = 0;
	long len = 1;
    if (ac == 2)
        return (ft_strdup(av[1]));
	while (++i < ac)
		len += ft_strlen(av[i]);
	len += i;
	res = malloc(len);
	i = 0;
    while (++i < ac)
        my_strlcat(res, av[i], len);
    return (res);
}

int	get_min_number(t_stack *stack, int *index)
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
	*index = n;
	return (lowest);
}

int	get_max_number(t_stack *stack, int *index)
{
	int i = stack->top;
	int bigest = stack->stack[i];
	int n = i;
	while (i > -1)
	{
		if (bigest < stack->stack[i])
		{
			bigest = stack->stack[i];
			n = i;
		}
		i--;
	}
	*index = n;
	return (bigest);
}

int get_index_of_operation(int *res, int len)
{
	int small = res[0];
	int idx = 0;
	int i = 0;
	while (i <= len)
	{
		if (res[i] <= small)
		{
			small = res[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int get_number_of_operation(int res[4], int *index)
{
	int small = res[0];
	int idx = 0;
	int i = 0;
	while (i < 4)
	{
		if (res[i] <= small)
		{
			small = res[i];
			idx = i;
		}
		i++;
	}
	*index = idx;
	return (small);
}