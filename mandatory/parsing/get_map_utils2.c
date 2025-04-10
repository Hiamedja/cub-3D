/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:54:24 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/22 00:08:04 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_f(t_cube *cube, int *i, int *flag)
{
	cube->error.f_e = 1;
	*i = *i + 1;
	*flag = *flag + 1;
}

void	check_c(t_cube *cube, int *i, int *flag)
{
	cube->error.c_e = 1;
	*i = *i + 1;
	*flag = *flag + 1;
}

void	checking_element(char **map, t_cube *cube, int *i, int *flag)
{
	while (map[*i] && *flag < 6)
	{
		if (!map[*i][0])
			*i = *i + 1;
		else if (!ft_strncmp(map[*i], "WE ", 3))
			check_we(map, cube, i, flag);
		else if (!ft_strncmp(map[*i], "NO ", 3))
			check_no(map, cube, i, flag);
		else if (!ft_strncmp(map[*i], "SO ", 3))
			check_so(map, cube, i, flag);
		else if (!ft_strncmp(map[*i], "EA ", 3))
			check_ea(map, cube, i, flag);
		else if (!ft_strncmp(map[*i], "F ", 2))
			check_f(cube, i, flag);
		else if (!ft_strncmp(map[*i], "C ", 2))
			check_c(cube, i, flag);
		else
			ft_error("Invalid map element");
	}
}
