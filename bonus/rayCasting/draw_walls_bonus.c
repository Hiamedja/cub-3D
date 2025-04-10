/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:32:23 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/30 00:34:26 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2_bonus.h"

void	ft_mlx_pixel_put(t_mlx_img *mlx_img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = mlx_img->addr + (y * mlx_img->line_length + x * \
		(mlx_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_ceil(t_raycasting *data, int i, \
	int top_position, unsigned int color)
{
	int	j;

	j = 0;
	while (j < top_position && top_position <= WINDOW_HEIGHT && j >= 0)
	{
		ft_mlx_pixel_put(data->mlx->mlx_img, i, j, color);
		j++;
	}
}

void	render_floor(t_raycasting *data, int i, \
	int bottom_position, unsigned int color)
{
	int	j;

	j = bottom_position;
	while (j < WINDOW_HEIGHT && j >= 0)
	{
		ft_mlx_pixel_put(data->mlx->mlx_img, i, j, color);
		j++;
	}
}

void	render_wall_slice(t_raycasting *data, int i)
{
	double	wall;
	double	top;
	double	bottom;
	double	ofst_x;
	t_coord	coord;

	if (data->ray_inf[i].wall_strip_height > WINDOW_HEIGHT)
		wall = WINDOW_HEIGHT;
	else
		wall = data->ray_inf[i].wall_strip_height;
	top = (WINDOW_HEIGHT / 2) - (wall / 2);
	bottom = (WINDOW_HEIGHT / 2) + (wall / 2);
	ofst_x = get_x_offset(data->ray_inf[i], data->texture);
	while (top < bottom)
	{
		coord.x = i;
		coord.y = top;
		put_textures(data, ofst_x, coord, i);
		top++;
	}
}

void	projection(t_raycasting *data, int i)
{
	int	wall_top_position;
	int	wall_bottom_position;

	wall_top_position = (WINDOW_HEIGHT / 2) \
		- (data->ray_inf[i].wall_strip_height / 2);
	if (wall_top_position < 0)
		wall_top_position = 0;
	wall_bottom_position = (WINDOW_HEIGHT / 2) + \
			(data->ray_inf[i].wall_strip_height / 2);
	if (wall_bottom_position > WINDOW_HEIGHT)
		wall_bottom_position = WINDOW_HEIGHT;
	render_ceil(data, i, wall_top_position, data->map_data->config.c);
	render_wall_slice(data, i);
	render_floor(data, i, wall_bottom_position, data->map_data->config.f);
}
