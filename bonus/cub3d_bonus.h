/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:52:28 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/30 00:40:36 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include "../libft/libft.h"

# define COUNT_MAP 10000

typedef struct s_config
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	f;
	unsigned int	c;

}	t_config;

typedef struct s_map
{
	int		x;
	int		y;
	char	**map;
}	t_map;

typedef struct s_error
{
	int	no_e;
	int	so_e;
	int	we_e;
	int	ea_e;
	int	f_e;
	int	c_e;
}	t_error;

typedef struct s_cube
{
	t_config	config;
	t_map		map;
	t_error		error;
	int			map_start;
	int			count;
	char		**new_map;
	int			map_size;
	int			map_lines;
	int			largest_line;
	int			start;
}	t_cube;

void	ft_check_name(char *name);
char	*ft_strjoin1(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_read_join(char *str, int fd);
char	*ft_get_line(char *str_sttc);
char	*ft_save(char *str_sttc);
char	**read_map(int c, int fd);
void	free_array(char **aray);
void	get_map(char **map, t_cube *cube);
int		fill_map(char *str);
void	init_config(t_cube *cube);
int		line_map(char *map, int fd);
int		check_element(char **map, t_cube *cube);
void	ft_check_colors(char **map, t_cube *cube);
char	**ft_check_walls(t_cube *cube);
int		ft_rgbisnum(char *s);
void	check_otherside(char *line);
void	check_spaces(t_cube *cube);
void	fill_map_with_spaces(t_cube *cube);
char	**fill_map_with_spaces3(t_cube *cube, int j);
int		largest_line(char **map);
void	check_last(char **map);
int		ft_strlen_array(char **map);
void	check_first(char **map);
void	check_otherside(char *line);
void	check_sides(char **map);
int		map_size(char **map, int i);
int		get_map_start(char **map, t_cube *cube);
void	check_c(t_cube *cube, int *i, int *flag);
void	check_f(t_cube *cube, int *i, int *flag);
void	check_so(char **map, t_cube *cube, int *i, int *flag);
void	check_ea(char **map, t_cube *cube, int *i, int *flag);
void	check_no(char **map, t_cube *cube, int *i, int *flag);
void	check_we(char **map, t_cube *cube, int *i, int *flag);
void	checking_element(char **map, t_cube *cube, int *i, int *flag);
char	**extract_map(char **map);
void	get_file(char **av, t_cube *cube);
void	parse(t_cube *cube);
void	free_map(char **map);
void	check_comma(char *s);

#endif
