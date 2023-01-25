/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:27:44 by esalim            #+#    #+#             */
/*   Updated: 2023/01/25 12:36:14 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int check_isdigits(char *str)
{
    int i = -1;
    while (str[++i])
        if (ft_isdigit(str[i]) == 0 && str[i] != '+' && str[i] != '-')
            return (0);
    return (1);
}

void  add_to_list(t_list **head, char   **num)
{
    int i = 0;
    int number;

    while (num[i])
    {
        if (!check_isdigits(num[i]))
        {
            ft_putstr_fd("Error: the argement should be a digits\n", 2);
            exit(1);
        }
        number = ft_atoi(num[i]);
        ft_lstadd_back(head, ft_lstnew(&number));
        i++;
    }
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

int main(int ac, char **av)
{
    char    *args = get_all_args(ac, av);
    char    **numbers = ft_split(args, ' ');
    t_list  *head = NULL;
    add_to_list(&head, numbers);
    while (head)
    {
        ft_printf("%d\n", *(int *)(head->content));
        head = head->next;
    }
    return (0);
}
