/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:45:09 by georgii           #+#    #+#             */
/*   Updated: 2022/10/17 11:46:17 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480
# define texWidth 64
# define texHeight 64

# define green 0x0000FF00
# define blue 0x000000FF
# define red 0x00FF0000

# define gray 0x6e6c67
# define light_blue 0x57f0f2
# define white 0xffffff
# define yellow 0xf5e942

# include <stdlib.h>
# include <stdio.h>
# include "../minilibx-opengl/mlx.h"
# include "../libft/libft.h"

typedef struct s_geom
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	int		texture_height;
	int		texture_width;

	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;

}	t_geom;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_img	img_data;
	t_geom	geom_data;
	t_img	tex[4];
	int		floor_color;
	int		ceiling_color;

}	t_data;

void	geom_init(t_geom *geom_data);
int		create_trgb(int t, int r, int g, int b);
void	img_init(t_data *data, t_img *img_data, size_t width, size_t height);
void	texture_init(t_data *data, t_img *img, char *path);

int		red_cross(void);
void	move_forward(t_geom *geom_data);
void	move_backward(t_geom *geom_data);
void	rotate_left(t_geom *geom_data);
void	rotate_right(t_geom *geom_data);
int		key_hook(int keycode, t_data *data);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_tex_color(t_img *img, int x, int y);
void	walls(t_data *data, t_geom *geom, t_img *img);
void	floor_ceiling(t_img *img, int f_color, int c_color);

void	ray_pos_dir(int x, t_geom *geom);
void	step_initial_side_dist(t_geom *geom);
void	perform_dda(t_geom *geom);
void	draw_start_end(t_geom *geom);
void	wall_x(t_geom *geom);

#endif
