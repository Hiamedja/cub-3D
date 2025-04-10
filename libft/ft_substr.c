/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:49:10 by hiamedja          #+#    #+#             */
/*   Updated: 2023/09/12 15:22:11 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	size_t	i;
	size_t	m;
	char	*str;

	i = 0;
	m = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		m = ft_strlen(s) - start;
	if (m > len)
		m = len;
	str = malloc(sizeof(char) * (m + 1));
	if (!str)
		return (NULL);
	while (i < m && s[start] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
