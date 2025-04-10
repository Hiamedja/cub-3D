/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:18:23 by hiamedja          #+#    #+#             */
/*   Updated: 2022/10/30 00:20:26 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenum(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nmb;
	char	*str;

	nmb = n;
	i = ft_lenum(nmb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (nmb == 0)
		str[0] = '0';
	str[i--] = '\0';
	if (nmb < 0)
	{
		str[0] = '-';
		nmb = -nmb;
	}
	while (nmb)
	{
		str[i--] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	return (str);
}
