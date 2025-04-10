/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:06:28 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/29 23:03:16 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_row_with_spaces(char *map, char *new_map, int j)
{
	int	k;

	k = 0;
	while (map[k])
	{
		if (map[k] == ' ')
			new_map[k] = '*';
		else
			new_map[k] = map[k];
		k++;
	}
	while (k < j)
	{
		new_map[k] = '*';
		k++;
	}
	new_map[k] = '\0';
}

char	**fill_map_with_spaces3(t_cube *cube, int j)
{
	int		i;
	char	**new_map;
	int		k;

	i = 0;
	k = 0;
	new_map = malloc(sizeof(char *) * COUNT_MAP);
	if (!new_map)
		ft_error("Failed memory allocation!!");
	while (cube->new_map[i])
	{
		new_map[i] = malloc(sizeof(char) * COUNT_MAP);
		if (!new_map[i])
			ft_error("Failed memory allocation!!");
		fill_row_with_spaces(cube->new_map[i], new_map[i], j);
		i++;
	}
	new_map[i] = NULL;
	while (new_map[k])
	{
		free(cube->new_map[k]);
		k++;
	}
	free(cube->new_map);
	return (new_map);
}

void	fill_map_with_spaces(t_cube *cube)
{
	cube->largest_line = largest_line(cube->new_map);
	cube->new_map = fill_map_with_spaces3(cube, cube->largest_line);
	check_spaces(cube);
}

char	**ft_check_walls(t_cube *cube)
{
	cube->map_lines = map_size(cube->new_map, 0);
	check_first(cube->new_map);
	check_sides(cube->new_map);
	check_last(cube->new_map);
	fill_map_with_spaces(cube);
	return (cube->new_map);
}
