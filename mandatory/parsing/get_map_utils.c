/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:31:58 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/29 23:47:50 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_we(char **map, t_cube *cube, int *i, int *flag)
{
	int	j;

	j = 3;
	while (map[*i][j] == ' ')
		j++;
	if (!map[*i][j])
		ft_error("Path must be set");
	cube->config.we = ft_strdup(&map[*i][j]);
	*i = *i + 1;
	cube->error.we_e = 1;
	*flag = *flag + 1;
}

void	check_no(char **map, t_cube *cube, int *i, int *flag)
{
	int	j;

	j = 3;
	while (map[*i][j] == ' ')
		j++;
	if (!map[*i][j])
		ft_error("Path must be set");
	cube->config.no = ft_strdup(&map[*i][j]);
	cube->error.no_e = 1;
	*i = *i + 1;
	*flag = *flag + 1;
}

void	check_ea(char **map, t_cube *cube, int *i, int *flag)
{
	int	j;

	j = 3;
	while (map[*i][j] == ' ')
		j++;
	if (!map[*i][j])
		ft_error("Path must be set");
	cube->config.ea = ft_strdup(&map[*i][j]);
	cube->error.ea_e = 1;
	*i = *i + 1;
	*flag = *flag + 1;
}

void	check_so(char **map, t_cube *cube, int *i, int *flag)
{
	int	j;

	j = 3;
	while (map[*i][j] == ' ')
		j++;
	if (!map[*i][j])
		ft_error("Path must be set");
	cube->config.so = ft_strdup(&map[*i][j]);
	cube->error.so_e = 1;
	*i = *i + 1;
	*flag = *flag + 1;
}
