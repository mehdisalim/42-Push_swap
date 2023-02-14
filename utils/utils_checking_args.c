/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checking_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:16:29 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 23:38:37 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_num_count(char **num)
{
	int	i;

	i = 0;
	while (num[i])
		i++;
	return (i);
}

int	check_isdigits(char *str)
{
	int	i;

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

char	*get_all_args(int ac, char **av)
{
	char	*res;
	int		i;
	long	len;

	i = 0;
	len = 1;
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

int	check_is_duplicated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack->top)
	{
		j = i + 1;
		while (j <= stack->top)
		{
			if (stack->stack[i] == stack->stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
