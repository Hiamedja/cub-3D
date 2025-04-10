/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_haswall_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:33:01 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/29 03:47:30 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2.h"

int	map_haswall_at(t_cube *map, double x, double y)
{
	int	xj;
	int	yi;

	xj = (int)floor(x / TILE_SIZE);
	yi = (int)floor(y / TILE_SIZE);
	if (xj < 0 || xj > map->largest_line || yi < 0 || \
		yi > map->map_lines)
		return (1);
	if (xj >= ft_strlen(map->new_map[yi]))
		return (1);
	return (map->new_map[yi][xj] == '1');
}
