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

void    ft_swap(char   **str1, char **str2)
{
    char    *tmp;

    tmp = ft_strjoin(*str1, *str2);
    free(*str1);
    *str1 = tmp;
}

char    *get_all_args(int ac, char **av)
{
    char    *res = malloc(1);
    int     i = 1;
    char    *space = " ";

    if (ac == 2)
        return (ft_strdup(av[1]));
    while (i < ac)
    {
        ft_swap(&res, &space);
        ft_swap(&res, &av[i]);
        i++;
    }
    return (res);
}

