/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:52:18 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/29 03:47:59 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2.h"

void	free_cube(t_raycasting *cube)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(cube->texture[i].text_data);
	free(cube->texture);
	free(cube->map_data->config.ea);
	free(cube->map_data->config.no);
	free(cube->map_data->config.so);
	free(cube->map_data->config.we);
	i = -1;
	while (cube->map_data->map.map[++i])
		free(cube->map_data->map.map[i]);
	free(cube->map_data->map.map[i]);
	i = -1;
	while (cube->map_data->new_map[++i])
		free(cube->map_data->new_map[i]);
	free(cube->map_data->new_map);
	free(cube->map_data);
}

int	destroy_cub(t_raycasting *data)
{
	printf("GAME OVER\n");
	free_cube(data);
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	exit(0);
	return (0);
}

int	cub_key_press(int key_code, t_raycasting *data)
{
	if (key_code == ESC)
		destroy_cub(data);
	if (key_code == ARROW_LEFT)
		data->player->rotation_direction = -1;
	if (key_code == ARROW_RIGHT)
		data->player->rotation_direction = 1;
	if (key_code == KEY_A)
		data->player->turn_l_r = -1;
	if (key_code == KEY_D)
		data->player->turn_l_r = 1;
	if (key_code == KEY_W)
		data->player->walk_direction = 1;
	if (key_code == KEY_S)
		data->player->walk_direction = -1;
	return (0);
}

int	cub_key_release(int key_code, t_raycasting *data)
{
	if (key_code == ARROW_LEFT)
		data->player->rotation_direction = 0;
	if (key_code == ARROW_RIGHT)
		data->player->rotation_direction = 0;
	if (key_code == KEY_A)
		data->player->turn_l_r = 0;
	if (key_code == KEY_D)
		data->player->turn_l_r = 0;
	if (key_code == KEY_W)
		data->player->walk_direction = 0;
	if (key_code == KEY_S)
		data->player->walk_direction = 0;
	return (0);
}
