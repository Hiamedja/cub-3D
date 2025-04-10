/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:31:09 by hiamedja          #+#    #+#             */
/*   Updated: 2022/10/29 17:26:24 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	t_list1	var;
	char	*str;

	var.i = 0;
	var.j = 0;
	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (!ft_strlen(s1))
	{
		str = malloc(1);
		*str = '\0';
		return (str);
	}
	var.len = ft_strlen(s1);
	while (ft_strchr((char *)set, s1[var.i]))
		var.i++;
	var.len2 = var.len;
	while (ft_strchr((char *)set, s1[var.len2 - 1]))
	{
		var.len2--;
		var.j++;
	}
	return (ft_substr(s1, var.i, var.len - var.i - var.j));
}
