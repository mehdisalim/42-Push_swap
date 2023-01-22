/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:27:44 by esalim            #+#    #+#             */
/*   Updated: 2023/01/22 13:59:39 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{

    char    **args = malloc(ac * sizeof(char *));
    int i = 1;
    int j = 0;

    while (i < ac)
        args[j++] = ft_strdup(av[i++]);
   /* 
    char    *args = ft_calloc((ac * 2) + 1, 1);
    int     x = 1;
    //char    *tmp;

    while (x < ac)
    {
        ft_strlcat(args, av[x], ft_strlen(av[x]) + ft_strlen(args));
        ft_strlcat(args, " ", ft_strlen(args) + 1);
        ft_printf("%s\n", args);
        x++;
    }*/
    
/*
    int stack_a[ac] = {0};
    int i = 1;
    int j = 0;
    while (i < ac)
    {
        stack_a[j] = ft_atoi(av[i]);
        ft_printf("%d\n", stack_a[j]);
        i++;
        j++;
    }*/
    return (0);
}
