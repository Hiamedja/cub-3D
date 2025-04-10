/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:42:01 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/29 16:22:40 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_2.h"

void	init_mlx_img(t_mlx *mlx, t_mlx_img *img)
{
	img->img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img->img)
		ft_error("Fail creating mlx image !!");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	mlx->mlx_img = img;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT, "");
}

void	initialize(t_player *p, char **map, t_mlx_img *img, t_mlx *mlx)
{
	init_player(p, map);
	init_mlx(mlx);
	init_mlx_img(mlx, img);
}

void	adding_path(t_texture *text, t_cube *map_data)
{
	text->height = TEXTURE_DIMENTION;
	text->width = TEXTURE_DIMENTION;
	text[0].path = map_data->config.no;
	text[1].path = map_data->config.so;
	text[2].path = map_data->config.we;
	text[3].path = map_data->config.ea;
}

t_texture	*init_textures(t_cube *map, void *mlx)
{
	int			i;
	t_texture	*text;

	i = -1;
	text = (t_texture *)malloc(4 * sizeof(t_texture));
	if (!text)
		ft_error("Memory allocation failed!!");
	adding_path(text, map);
	while (++i < 4)
	{
		text[i].text_data = (t_mlx_img *)malloc(sizeof(t_mlx_img));
		if (!text[i].text_data)
			ft_error("Memory allocation failed!!");
		text[i].text_data->img = mlx_xpm_file_to_image(mlx, text[i].path, \
			&text[i].width, &text[i].height);
		if (!text[i].text_data->img)
			ft_error("Img file not found!!");
		text[i].text_data->text_addr = (int *)
			mlx_get_data_addr(text[i].text_data->img, \
			&text[i].text_data->bits_per_pixel, \
			&text[i].text_data->line_length, &text[i].text_data->endian);
		if (!text[i].text_data->text_addr)
			ft_error("Img addr not found!!");
	}
	return (text);
}
