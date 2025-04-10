/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:58:03 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/28 07:05:35 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_2.h"

void	first_viewangle_of_player(t_player *player, char **map)
{
	int		x;
	int		y;
	char	p_view;

	x = (int)(player->vector_pos.x / TILE_SIZE);
	y = (int)(player->vector_pos.y / TILE_SIZE);
	p_view = map[y][x];
	if (p_view == 'S')
		player->angle = 0.5 * M_PI;
	else if (p_view == 'N')
		player->angle = 1.5 * M_PI;
	else if (p_view == 'E')
		player->angle = 0;
	else if (p_view == 'W')
		player->angle = M_PI;
}

void	player_vector(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '*')
			{
				player->vector_pos.x = j * TILE_SIZE + (TILE_SIZE / 2);
				player->vector_pos.y = i * TILE_SIZE + (TILE_SIZE / 2);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_player *player, char **map)
{
	player_vector(player, map);
	first_viewangle_of_player(player, map);
	player->fov = 60 * (M_PI / 180);
	player->walk_direction = 0;
	player->turn_l_r = 0;
	player->rotation_direction = 0;
	player->rotation_speed = ROTATION_SPEED;
	player->walk_speed = 2.05;
}
