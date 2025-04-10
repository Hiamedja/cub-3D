/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:57:26 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/30 00:34:08 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2_bonus.h"

void	get_the_nearest_wall(t_player *player, t_ray *ray)
{
	double	horizdistance;
	double	verticdistance;

	horizdistance = get_dist(player, ray->horizhit);
	verticdistance = get_dist(player, ray->vertichit);
	ray->vertical_hitside = false;
	if (horizdistance <= verticdistance)
	{
		ray->dist = horizdistance * cos(ray->angle - player->angle);
		ray->wall_hit = ray->horizhit;
	}
	else
	{
		ray->vertical_hitside = true;
		ray->dist = verticdistance * cos(ray->angle - player->angle);
		ray->wall_hit = ray->vertichit;
	}
}

t_ray	raycast(t_raycasting *data, double ray_angle)
{
	t_ray	ray;

	ray.angle = normalize_angle(ray_angle);
	ray_direction(&ray);
	find_horizontal_intersect(data, &ray);
	find_vertical_intersect(data, &ray);
	get_the_nearest_wall(data->player, &ray);
	return (ray);
}
