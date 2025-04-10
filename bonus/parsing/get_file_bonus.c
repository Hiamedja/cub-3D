/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:33:15 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/30 00:32:01 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		ft_error("fd not valid.");
	return (fd);
}

int	line_map(char *map, int fd)
{
	int		count;
	char	*line;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Map file not found.");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\0')
			count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**read_map(int c, int fd)
{
	char	**line;
	int		i;
	int		len;

	i = 0;
	line = (char **)malloc(sizeof(char *) * COUNT_MAP);
	if (!line)
		exit(-1);
	while (i < c)
	{
		line[i] = get_next_line(fd);
		len = ft_strlen(line[i]);
		if (len > 0 && line[i][len - 1] == '\n')
			line[i][len - 1] = '\0';
		i++;
	}
	line[i] = NULL;
	close(fd);
	return (line);
}

void	get_file(char **av, t_cube *cube)
{
	int	fd;

	ft_check_name(av[1]);
	fd = open_file(av[1]);
	cube->count = line_map(av[1], fd);
	cube->map.map = read_map(cube->count, fd);
}
