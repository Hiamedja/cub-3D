/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_comma.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:59:36 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/29 19:59:49 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_comma(char *s)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (s[i])
	{
		if (s[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		ft_error("RGB colors are wrong!!");
}
