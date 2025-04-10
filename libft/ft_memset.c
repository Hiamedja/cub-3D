/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:34:59 by hiamedja          #+#    #+#             */
/*   Updated: 2022/10/30 18:43:09 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int a, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	c;

	i = 0;
	s = (unsigned char *)str;
	c = (unsigned char) a;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
