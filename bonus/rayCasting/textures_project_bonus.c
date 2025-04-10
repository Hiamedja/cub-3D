/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_project_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:29:28 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/30 00:37:36 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_2_bonus.h"

void	put_vertic_textures(t_raycasting *data, double ofst_x, \
	t_coord co, double dst)
{
	double	ofst_y;

	if (data->ray_inf[(int)co.x].looking_left == 1)
	{
		ofst_y = floor(dst / data->ray_inf[(int)co.x].wall_strip_height * \
			((float)data->texture[2].height));
		if (ofst_x < 0 || ofst_y < 0 || ofst_x > data->texture[2].width
			|| ofst_y > data->texture[2].height)
			return ;
		ft_mlx_pixel_put(data->mlx->mlx_img, co.x, co.y,
			data->texture[2].text_data->text_addr[(int) \
				((ofst_y * data->texture[2].width) + ofst_x)]);
	}
	else if (data->ray_inf[(int)co.x].looking_right == 1)
	{
		ofst_y = floor(dst / data->ray_inf[(int)co.x].wall_strip_height * \
			((float)data->texture[3].height));
		if (ofst_x < 0 || ofst_y < 0 || ofst_x > data->texture[3].width
			|| ofst_y > data->texture[3].height)
			return ;
		ft_mlx_pixel_put(data->mlx->mlx_img, co.x, co.y,
			data->texture[3].text_data->text_addr[(int) \
				((ofst_y * data->texture[3].width) + ofst_x)]);
	}
}

void	put_horiz_textures(t_raycasting *data, double ofst_x, \
	t_coord co, double dst)
{
	double	ofst_y;

	if (data->ray_inf[(int)co.x].looking_down == 1)
	{
		ofst_y = floor(dst / data->ray_inf[(int)co.x].wall_strip_height * \
			((float)data->texture[1].height));
		if (ofst_x < 0 || ofst_y < 0 || ofst_x > data->texture[1].width
			|| ofst_y > data->texture[1].height)
			return ;
		ft_mlx_pixel_put(data->mlx->mlx_img, co.x, co.y,
			data->texture[1].text_data->text_addr[(int) \
				((ofst_y * data->texture[1].width) + ofst_x)]);
	}
	else if (data->ray_inf[(int)co.x].looking_up == 1)
	{
		ofst_y = floor(dst / data->ray_inf[(int)co.x].wall_strip_height * \
			((float)data->texture[0].height));
		if (ofst_x < 0 || ofst_y < 0 || ofst_x > data->texture[0].width
			|| ofst_y > data->texture[0].height)
			return ;
		ft_mlx_pixel_put(data->mlx->mlx_img, co.x, co.y,
			data->texture[0].text_data->text_addr[(int) \
				((ofst_y * data->texture[0].width) + ofst_x)]);
	}
}

void	put_textures(t_raycasting *data, double ofst_x, t_coord coord, int i)
{
	double	dist_from_top;

	dist_from_top = coord.y + \
		(data->ray_inf[i].wall_strip_height / 2) - (WINDOW_HEIGHT / 2);
	if (data->ray_inf[i].vertical_hitside == true)
		put_vertic_textures(data, ofst_x, coord, dist_from_top);
	else
		put_horiz_textures(data, ofst_x, coord, dist_from_top);
}

double	get_x_offset(t_ray ray, t_texture *texture)
{
	double	offset_x;

	offset_x = 0;
	if (ray.vertical_hitside == true)
	{
		if (ray.looking_left == 1)
			offset_x = fmod(ray.wall_hit.y, TILE_SIZE) / \
				TILE_SIZE * texture[2].width;
		else if (ray.looking_right == 1)
			offset_x = fmod(ray.wall_hit.y, TILE_SIZE) / \
				TILE_SIZE * texture[3].width;
	}
	else
	{
		if (ray.looking_down == 1)
			offset_x = fmod(ray.wall_hit.x, TILE_SIZE) / \
				TILE_SIZE * texture[1].width;
		else if (ray.looking_up == 1)
			offset_x = fmod(ray.wall_hit.x, TILE_SIZE) / \
				TILE_SIZE * texture[0].width;
	}
	return (offset_x);
}
