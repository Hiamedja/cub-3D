/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_calcul_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:33:07 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/30 00:36:27 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2_bonus.h"

double	normalize_angle(double angle)
{
	double	result;

	result = fmod(angle, 2 * M_PI);
	if (result < 0)
		result += 2 * M_PI;
	return (result);
}

double	get_dist(t_player *player, t_coord hit)
{
	return (sqrt(pow(hit.x - player->vector_pos.x, 2) + \
		pow(hit.y - player->vector_pos.y, 2)));
}
