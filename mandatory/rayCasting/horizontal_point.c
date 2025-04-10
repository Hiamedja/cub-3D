/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:34:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/29 03:45:28 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2.h"

t_coord	find_horizontal_intercept(t_player *player, t_ray *ray)
{
	t_coord	intercept;

	intercept.y = floor(player->vector_pos.y / TILE_SIZE) * TILE_SIZE;
	if (ray->looking_down == 1)
		intercept.y += TILE_SIZE;
	intercept.x = (intercept.y - player->vector_pos.y) / tan(ray->angle) + \
				player->vector_pos.x;
	return (intercept);
}

t_coord	find_horizontal_step(t_ray *ray)
{
	t_coord	step;

	step.y = TILE_SIZE;
	if (ray->looking_up == 1)
		step.y *= -1;
	step.x = TILE_SIZE / tan(ray->angle);
	if ((ray->looking_right == 1 && step.x < 0)
		|| (ray->looking_left == 1 && step.x > 0))
		step.x *= -1;
	return (step);
}

void	find_horizontal_intersect(t_raycasting *data, t_ray *ray)
{
	t_coord	step;
	double	check;

	check = 0;
	if (ray->looking_up == 1)
		check = 1;
	ray->horizhit = find_horizontal_intercept(data->player, ray);
	step = find_horizontal_step(ray);
	while (ray->horizhit.x >= 0
		&& ray->horizhit.x <= (data->map_data->largest_line - 1) * TILE_SIZE
		&& ray->horizhit.y >= 0
		&& ray->horizhit.y <= (data->map_data->map_lines - 1) * TILE_SIZE)
	{
		if (map_haswall_at(data->map_data, ray->horizhit.x,
				ray->horizhit.y - check))
			return ;
		else
		{
			ray->horizhit.x += step.x;
			ray->horizhit.y += step.y;
		}
	}
}
