/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:13:08 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/22 00:07:40 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_name(char *name)
{
	int		i;
	int		j;
	char	*h;

	i = 0;
	j = ft_strlen(name);
	if (j < 5)
		ft_error("Check the name of ur map");
	h = ft_strdup(".cub");
	while (name[j - 4 + i] != '\0' && i < j)
	{
		if (name[j - 4 + i] != h[i])
		{
			free(h);
			ft_error("Please enter a valid map file (.cub)!");
		}
		i++;
	}
	free(h);
}
