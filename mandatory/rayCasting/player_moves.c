/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:33:15 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/29 03:26:36 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2.h"

void	_walk_l_r(t_raycasting *data)
{
	double	move_step;
	double	side_angle;
	double	new_player_x;
	double	new_player_y;

	move_step = data->player->walk_speed;
	side_angle = 0;
	if (data->player->walk_direction == -1)
		side_angle = data->player->angle + \
			(data->player->turn_l_r * (M_PI / 2));
	else
		side_angle = data->player->walk_direction * \
			(data->player->angle + (data->player->turn_l_r * (M_PI / 4)));
	new_player_x = data->player->vector_pos.x + (cos(side_angle) * move_step);
	new_player_y = data->player->vector_pos.y + (sin(side_angle) * move_step);
	if (!map_haswall_at(data->map_data, new_player_x, new_player_y)
		&& !map_haswall_at(data->map_data, new_player_x + 2, new_player_y + 2)
		&& !map_haswall_at(data->map_data, new_player_x + 2, new_player_y - 2)
		&& !map_haswall_at(data->map_data, new_player_x - 2, new_player_y - 2)
		&& !map_haswall_at(data->map_data, new_player_x - 2, new_player_y + 2))
	{
		data->player->vector_pos.x = new_player_x;
		data->player->vector_pos.y = new_player_y;
	}
}

void	_turning(t_raycasting *data)
{
	double	move_step;
	double	new_player_x;
	double	new_player_y;
	double	angle_incr;

	angle_incr = 0;
	move_step = data->player->walk_speed;
	angle_incr = data->player->turn_l_r * (M_PI / 2);
	new_player_x = data->player->vector_pos.x + (cos(data->player->angle + \
			angle_incr) * move_step);
	new_player_y = data->player->vector_pos.y + (sin(data->player->angle + \
			angle_incr) * move_step);
	if (!map_haswall_at(data->map_data, new_player_x, new_player_y)
		&& !map_haswall_at(data->map_data, new_player_x + 2, new_player_y + 2)
		&& !map_haswall_at(data->map_data, new_player_x + 2, new_player_y - 2)
		&& !map_haswall_at(data->map_data, new_player_x - 2, new_player_y - 2)
		&& !map_haswall_at(data->map_data, new_player_x - 2, new_player_y + 2))
	{
		data->player->vector_pos.x = new_player_x;
		data->player->vector_pos.y = new_player_y;
	}
}

void	_moving_forward_backward(t_raycasting *data)
{
	double	move_step;
	double	new_player_x;
	double	new_player_y;

	move_step = data->player->walk_direction * data->player->walk_speed;
	new_player_x = data->player->vector_pos.x + \
		(cos(data->player->angle) * move_step);
	new_player_y = data->player->vector_pos.y + \
		(sin(data->player->angle) * move_step);
	if (!map_haswall_at(data->map_data, new_player_x, new_player_y)
		&& !map_haswall_at(data->map_data, new_player_x + 2, new_player_y + 2)
		&& !map_haswall_at(data->map_data, new_player_x + 2, new_player_y - 2)
		&& !map_haswall_at(data->map_data, new_player_x - 2, new_player_y - 2)
		&& !map_haswall_at(data->map_data, new_player_x - 2, new_player_y + 2))
	{
		data->player->vector_pos.x = new_player_x;
		data->player->vector_pos.y = new_player_y;
	}
}

void	player_moves(t_raycasting *data)
{
	data->player->angle += normalize_angle(data->player->rotation_direction * \
		data->player->rotation_speed);
	if (data->player->turn_l_r != 0 && data->player->walk_direction != 0)
		_walk_l_r(data);
	else if (data->player->turn_l_r != 0)
		_turning(data);
	else if (data->player->walk_direction != 0)
		_moving_forward_backward(data);
}
