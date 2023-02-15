/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:21:06 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 17:23:05 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	d = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d)
		return (0);
	while (s1[j])
		d[i++] = s1[j++];
	while (*s2)
		d[i++] = *s2++;
	d[i] = 0;
	return (d);
}
