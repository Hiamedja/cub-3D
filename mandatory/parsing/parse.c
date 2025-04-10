/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:39:17 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/29 23:04:03 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	parse(t_cube *cube)
{
	get_map(cube->map.map, cube);
	ft_check_colors(cube->map.map, cube);
	cube->new_map = extract_map(cube->map.map);
	cube->new_map = ft_check_walls(cube);
}
