/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:54:57 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/30 00:32:20 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	fill_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

void	check_second_map_part(char **map, int i)
{
	int	j;

	while (map[i])
	{
		if (!map[i][0])
			i++;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' \
				&& map[i][j] != ' ' && map[i][j] != 'N' \
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
				ft_error("Unknown element in map!!");
			j++;
		}
		i++;
	}
}

void	check_map(char **map, int k)
{
	int	j;
	int	p_count;

	p_count = 0;
	while (map[k])
	{
		j = 0;
		while (map[k][j])
		{
			if (map[k][j] == 'N' || map[k][j] == 'S' \
				|| map[k][j] == 'E' || map[k][j] == 'W')
				p_count++;
			j++;
		}
		k++;
	}
	if (p_count != 1)
		ft_error("Extra or missing map player!!");
}

int	check_element(char **map, t_cube *cube)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (map[i] == NULL)
		ft_error("Empty map!!");
	checking_element(map, cube, &i, &flag);
	if (cube->error.f_e != 1 || cube->error.c_e != 1 \
		|| cube->error.no_e != 1 || cube->error.so_e != 1
		|| cube->error.we_e != 1 || cube->error.ea_e != 1)
		ft_error("Invalid map element!!");
	return (i);
}

void	get_map(char **map, t_cube *cube)
{
	int	j;

	init_config(cube);
	j = check_element(map, cube);
	if (map[j] == NULL)
		ft_error("Empty map!!");
	check_second_map_part(map, j);
	check_map(map, j);
}
