/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:45:09 by hiamedja          #+#    #+#             */
/*   Updated: 2022/10/29 20:01:28 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int a, size_t n)
{
	unsigned char	*s1;
	unsigned char	c;
	size_t			i;

	i = 0;
	c = (unsigned char) a;
	s1 = (unsigned char *)str;
	while (i < n)
	{
		if (s1[i] == c)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
