/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_point_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:33:29 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/30 00:37:55 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2_bonus.h"

t_coord	find_vertical_intercept(t_player *player, t_ray *ray)
{
	t_coord	intercept;

	intercept.x = floor(player->vector_pos.x / TILE_SIZE) * TILE_SIZE;
	if (ray->looking_right == 1)
		intercept.x += TILE_SIZE;
	intercept.y = tan(ray->angle) * (intercept.x - player->vector_pos.x) + \
				player->vector_pos.y;
	return (intercept);
}

t_coord	find_vertical_step(t_ray *ray)
{
	t_coord	step;

	step.x = TILE_SIZE;
	if (ray->looking_left == 1)
		step.x *= -1;
	step.y = tan(ray->angle) * TILE_SIZE;
	if ((ray->looking_up == 1 && step.y > 0)
		|| (ray->looking_down == 1 && step.y < 0))
		step.y *= -1;
	return (step);
}

void	find_vertical_intersect(t_raycasting *data, t_ray *ray)
{
	t_coord	step;
	double	check;

	check = 0;
	if (ray->looking_left == 1)
		check = 1;
	ray->vertichit = find_vertical_intercept(data->player, ray);
	step = find_vertical_step(ray);
	while (ray->vertichit.x >= 0
		&& ray->vertichit.x < (data->map_data->largest_line * TILE_SIZE)
		&& ray->vertichit.y >= 0
		&& ray->vertichit.y < (data->map_data->map_lines * TILE_SIZE))
	{
		if (map_haswall_at(data->map_data, ray->vertichit.x - check,
				ray->vertichit.y))
			return ;
		else
		{
			ray->vertichit.x += step.x;
			ray->vertichit.y += step.y;
		}
	}
}
