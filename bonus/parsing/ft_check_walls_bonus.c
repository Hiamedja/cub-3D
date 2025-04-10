/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:47:05 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/30 00:30:54 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	get_map_start(char **map, t_cube *cube)
{
	int	i;
	int	j;

	(void)cube;
	i = 0;
	j = 0;
	while (map[i] && map[i][0] != '1' && map[i][0] != ' ')
		i++;
	return (i);
}

int	map_size(char **map, int i)
{
	int	size;

	size = 0;
	while (map[i])
	{
		size++;
		i++;
	}
	return (size);
}

void	check_sides(char **map)
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (map[i][j] == ' ')
				j++;
			if (map[i][j] != '1')
				ft_error("The map must be surrounded by walls on the 1st side");
			check_otherside(map[i]);
			break ;
		}
		i++;
	}
}

void	check_otherside(char *line)
{
	int	i;

	i = ft_strlen(line);
	while (line[i - 1] == ' ')
		i--;
	if (line[i - 1] != '1')
		ft_error("The map must be surrounded by walls in the other side");
}

void	check_first(char **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			ft_error("The map must be surrounded by walls in the beginning");
		j++;
	}
}
