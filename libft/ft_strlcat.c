/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:24:47 by hiamedja          #+#    #+#             */
/*   Updated: 2022/10/30 00:52:06 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	delen;
	size_t	srcl;

	i = 0;
	if ((!dst || !src) && dstsize == 0)
		return (0);
	srcl = ft_strlen(src);
	delen = ft_strlen(dst);
	if (dstsize < delen + 1)
		return (dstsize + srcl);
	if (dstsize > delen + 1)
	{
		while (src[i] && dstsize > delen + 1 + i)
		{
			dst[delen + i] = src[i];
			i++;
		}
	}
	dst[delen + i] = '\0';
	return (srcl + delen);
}
