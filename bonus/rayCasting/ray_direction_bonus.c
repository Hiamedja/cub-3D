/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:12:42 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/30 00:36:58 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2_bonus.h"

void	ray_direction(t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < M_PI)
	{
		ray->looking_down = 1;
		ray->looking_up = 0;
	}
	else
	{
		ray->looking_up = 1;
		ray->looking_down = 0;
	}
	if ((ray->angle < 1.5 * M_PI) && (ray->angle > 0.5 * M_PI))
	{
		ray->looking_left = 1;
		ray->looking_right = 0;
	}
	else if ((ray->angle > 1.5 * M_PI) || (ray->angle < 0.5 * M_PI))
	{
		ray->looking_right = 1;
		ray->looking_left = -1;
	}
}
