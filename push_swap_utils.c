#include "push_swap.h"

int check_isdigits(char *str)
{
    int i = -1;
    while (str[++i])
        if (ft_isdigit(str[i]) == 0 && str[0] != '+' && str[0] != '-')
            return (0);
    return (1);
}

int get_num_count(char   **num)
{
    int i = -1;
    while (num[++i]);
    return (i);
}

// char    *ft_join(char   *str1, char *str3)
// {
// 	char	*res;
//     res = ft_strjoin(str1, " ");
// 	// free(str1);
// 	str1 = ft_strjoin(res, str3);
// 	// free(res);
// 	if (!str1)
// 	{
// 		ft_putendl_fd("ft_strjoin error", 2);
// 		exit(1);
// 	}
// 	return (str1);
// }

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	d = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!d)
		return (0);
	while (s1[j])
		d[i++] = s1[j++];
	d[i++] = ' ';
	while (*s2)
		d[i++] = *s2++;
	d[i] = 0;
	free((char *)s1);
	return (d);
}

char    *get_all_args(int ac, char **av)
{
    char    *res = malloc(1);
    int     i = 0;
    if (ac == 2)
        return (ft_strdup(av[1]));
    while (++i < ac)
        res = my_strjoin(res, av[i]);
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