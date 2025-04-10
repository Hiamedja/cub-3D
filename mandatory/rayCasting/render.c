/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:49:55 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/29 02:43:12 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2.h"

void	render_3d(t_raycasting *data)
{
	int		i;
	double	dist_to_projection_plane;

	mlx_clear_window(data->mlx->mlx, data->mlx->mlx_win);
	i = 0;
	dist_to_projection_plane = (WINDOW_WIDTH / 2) / \
		(tan(data->player->fov / 2));
	while (i < NBR_OF_RAYS)
	{
		data->ray_inf[i].wall_strip_height = (TILE_SIZE / \
			data->ray_inf[i].dist) * dist_to_projection_plane;
		projection(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->mlx_img->img, 0, 0);
	free(data->ray_inf);
}

int	render(t_raycasting *data)
{
	double	ray_angle;
	int		i;

	player_moves(data);
	mlx_clear_window(data->mlx->mlx, data->mlx->mlx_win);
	data->ray_inf = (t_ray *)malloc(sizeof(t_ray) * NBR_OF_RAYS);
	if (!data->ray_inf)
		ft_error("Failed memory allocation!!");
	ray_angle = data->player->angle - (data->player->fov / 2);
	i = 0;
	while (i < NBR_OF_RAYS)
	{
		ray_angle = normalize_angle(ray_angle);
		data->ray_inf[i] = raycast(data, ray_angle);
		ray_angle += data->player->fov / NBR_OF_RAYS;
		i++;
	}
	render_3d(data);
	return (1);
}
