/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:52:54 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/29 23:03:38 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_num(char **s, t_cube *cube, int flag)
{
	int	num;
	int	i;

	i = 0;
	while (i < 3)
	{
		num = ft_atoi(s[i]);
		if (num < 0 || num > 255 || (ft_strlen(s[i]) == 4))
			ft_error("RGB colors should be in range of [0,255]");
		if (ft_rgbisnum(s[i]))
			ft_error("RGB colors should be number");
		i++;
	}
	if (flag == 1)
		cube->config.f = (ft_atoi(s[0]) << 16) | (ft_atoi(s[1]) << 8)
			| (ft_atoi(s[2]));
	else if (flag == 2)
		cube->config.c = (ft_atoi(s[0]) << 16) | (ft_atoi(s[1]) << 8)
			| (ft_atoi(s[2]));
}

void	check_rgb(char **map, int i, t_cube *cube, int flag)
{
	int		j;
	char	**split1;

	split1 = NULL;
	j = 0;
	split1 = ft_split(&map[i][j], ',');
	if (!split1 || !split1[0] || !split1[1] || !split1[2] || split1[3])
		ft_error("More or less RGB colors !!");
	if (split1 && split1[0])
		check_num(split1, cube, flag);
	free_array(split1);
}

void	ft_get_floor_color(char *line, t_cube *cube)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		ft_error("Floor color!!");
	check_comma(split[1]);
	check_rgb(split, 1, cube, 1);
	free_array(split);
}

void	ft_get_ceiling_color(char *line, t_cube *cube)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		ft_error("Ceiling color!!");
	check_comma(split[1]);
	check_rgb(split, 1, cube, 2);
	free_array(split);
}

void	ft_check_colors(char **map, t_cube *cube)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == 'F')
			ft_get_floor_color(map[i], cube);
		if (map[i][0] == 'C')
			ft_get_ceiling_color(map[i], cube);
		i++;
	}
}
