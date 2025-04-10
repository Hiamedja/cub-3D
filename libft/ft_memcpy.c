/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:08:26 by hiamedja          #+#    #+#             */
/*   Updated: 2022/10/30 00:27:41 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sc;
	unsigned char	*dst;

	i = 0;
	if (dest == src)
		return (dest);
	if (dest == NULL && src == NULL)
	{
		return (dest);
	}
	sc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dst);
}
