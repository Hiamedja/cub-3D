/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:03:28 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/30 00:30:19 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_strlen_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_last(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen_array(map) - 1;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			ft_error("The map must be surrounded by walls in the end");
		j++;
	}	
}

int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_spaces(t_cube *cube)
{
	int	j;
	int	i;

	i = 0;
	while (cube->new_map[i] && i < cube->map_lines)
	{
		j = 0;
		while (cube->new_map[i][j] && j < ft_strlen(cube->new_map[i]))
		{
			if ((cube->new_map[i][j] == '0' || cube->new_map[i][j] == 'N' \
				|| cube->new_map[i][j] == 'E' || cube->new_map[i][j] == 'W' \
				|| cube->new_map[i][j] == 'S') \
				&& ((cube->new_map[i][j + 1] == '*' \
				|| cube->new_map[i][j - 1] == '*') \
				|| (cube->new_map[i + 1][j] == '*' \
				|| cube->new_map[i - 1][j] == '*')))
				ft_error("The map must be surrounded by walls in spaces");
			j++;
		}
		i++;
	}
}

int	largest_line(char **map)
{
	int	max_len;
	int	curr_len;
	int	i;

	max_len = 0;
	i = 0;
	while (map[i])
	{
		curr_len = ft_strlen(map[i]);
		if (curr_len > max_len)
			max_len = curr_len;
		i++;
	}
	return (max_len);
}
