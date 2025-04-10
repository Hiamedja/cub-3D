/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:30:48 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/29 14:31:03 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**extract_map(char **map)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = NULL;
	while (map[i] && map[i][0] != '1' && map[i][0] != ' ')
		i++;
	result = (char **)malloc(sizeof(char *) * COUNT_MAP);
	if (!result)
		exit(EXIT_FAILURE);
	while (map[i])
	{
		result[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	result[j] = NULL;
	return (result);
}
