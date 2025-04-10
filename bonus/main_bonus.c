/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:52:06 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/30 00:40:05 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_2_bonus.h"

int	main(int ac, char **av)
{
	t_player		player;
	t_cube			*cube;
	t_mlx			mlx;
	t_mlx_img		img;
	t_raycasting	data;

	if (ac != 2)
		ft_error("We must have 1 argument");
	cube = malloc(sizeof(t_cube));
	get_file(av, cube);
	parse(cube);
	initialize(&player, cube->new_map, &img, &mlx);
	data.texture = init_textures(cube, mlx.mlx);
	data.mlx = &mlx;
	data.player = &player;
	data.map_data = cube;
	mlx_hook(data.mlx->mlx_win, 2, 1L << 0, cub_key_press, &data);
	mlx_hook(data.mlx->mlx_win, 3, 1L << 0, cub_key_release, &data);
	mlx_hook(data.mlx->mlx_win, 17, 1L, destroy_cub, &data);
	mlx_loop_hook(data.mlx->mlx, render, &data);
	mlx_loop(data.mlx->mlx);
	return (0);
}
