/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:11:18 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/11/29 04:00:25 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_2_H
# define CUB3D_2_H

# define WINDOW_WIDTH 1250
# define WINDOW_HEIGHT 750
# define NBR_OF_RAYS WINDOW_WIDTH
# define TILE_SIZE 64
# define TEXTURE_DIMENTION 64
# define ROTATION_SPEED 0.04

# include "cub3d.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>

enum	e_key
{
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S,
	KEY_D
};

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		*text_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_img	*mlx_img;
}	t_mlx;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_ray
{
	double	angle;
	double	dist;
	t_coord	horizhit;
	t_coord	vertichit;
	t_coord	wall_hit;
	int		looking_up;
	int		looking_down;
	int		looking_left;
	int		looking_right;
	int		wall_strip_height;
	bool	vertical_hitside;
}	t_ray;

typedef struct s_player
{
	t_coord	vector_pos;
	double	fov;
	double	angle;
	int		turn_l_r;
	int		walk_direction;
	int		rotation_direction;
	double	rotation_speed;
	double	walk_speed;
}	t_player;

typedef struct s_texture
{
	t_mlx_img	*text_data;
	int			width;
	int			height;
	char		*path;
}	t_texture;

typedef struct s_raycasting
{
	t_player	*player;
	t_mlx		*mlx;
	t_cube		*map_data;
	t_ray		*ray_inf;
	t_texture	*texture;
}	t_raycasting;

void		initialize(t_player *p, char **map, t_mlx_img *img, t_mlx *mlx);
void		init_player(t_player *player, char **map);
void		player_vector(t_player *player, char **map);
void		first_viewangle_of_player(t_player *player, char **map);
void		init_mlx(t_mlx *mlx);
void		init_mlx_img(t_mlx *mlx, t_mlx_img *img);
int			destroy_cub(t_raycasting *data);
int			cub_key_press(int key_code, t_raycasting *data);
int			cub_key_release(int key_code, t_raycasting *data);
int			render(t_raycasting *data);
void		player_moves(t_raycasting *data);
void		_moving_forward_backward(t_raycasting *data);
void		_turning(t_raycasting *data);
void		_walk_l_r(t_raycasting *data);
t_ray		raycast(t_raycasting *data, double ray_angle);
double		normalize_angle(double angle);
void		ray_direction(t_ray *ray);
int			map_haswall_at(t_cube *map, double x, double y);
void		find_horizontal_intersect(t_raycasting *data, t_ray *ray);
t_coord		find_horizontal_intercept(t_player *player, t_ray *ray);
t_coord		find_horizontal_step(t_ray *ray);
void		find_vertical_intersect(t_raycasting *data, t_ray *ray);
t_coord		find_vertical_intercept(t_player *player, t_ray *ray);
t_coord		find_vertical_step(t_ray *ray);
void		get_the_nearest_wall(t_player *player, t_ray *ray);
double		get_dist(t_player *player, t_coord hit);
void		projection(t_raycasting *data, int i);
void		render_ceil(t_raycasting *data, int i, \
			int top_position, unsigned int color);
void		render_wall_slice(t_raycasting *data, int i);
void		render_floor(t_raycasting *data, int i, \
			int bottom_position, unsigned int color);
void		ft_mlx_pixel_put(t_mlx_img *mlx_img, int x, int y, int color);
void		adding_path(t_texture *data, t_cube *map_data);
t_texture	*init_textures(t_cube *map, void *mlx);
double		get_x_offset(t_ray ray, t_texture *texture);
void		put_textures(t_raycasting *data, double ofst_x, \
			t_coord coord, int i);
void		put_vertic_textures(t_raycasting *data, \
			double ofst_x, t_coord co, double dst);
void		put_horiz_textures(t_raycasting *data, \
			double ofst_x, t_coord co, double dst);

#endif
