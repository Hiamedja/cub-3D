/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:00:49 by hiamedja          #+#    #+#             */
/*   Updated: 2022/10/29 20:02:02 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sc;
	unsigned char	*dst;

	i = 0;
	if (dest == src)
		return (dest);
	if (dest == NULL && src == NULL)
		return (dest);
	sc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (dst > sc)
	{
		while (n > 0)
		{
			dst[n - 1] = sc[n - 1];
			n--;
		}
	}
	while (i < n)
	{
			dst[i] = sc[i];
			i++;
	}
	return (dest);
}
