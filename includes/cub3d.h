/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:45:09 by georgii           #+#    #+#             */
/*   Updated: 2022/09/11 18:23:18 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBHEAD_H
# define CUBHEAD_H

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64

#define green 0x0000FF00
#define blue 0x000000FF
#define red 0x00FF0000

#define gray 0x6e6c67
#define light_blue 0x57f0f2
#define white 0xffffff
#define yellow 0xf5e942

#include <stdlib.h>
#include <stdio.h>

#include "../minilibx-opengl/mlx.h"
#include "../libft/libft.h"


typedef struct s_geom
{
	double	posX;
	double	posY; 
  	double	dirX;
	double	dirY;
  	double	planeX;
	double	planeY;
	double	moveSpeed;
	double	rotSpeed;
	int		textureHeight;
	int		textureWidth;

}	t_geom;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_data {

	void	*mlx;
	void	*mlx_win;
	t_img	img_data;
	t_geom	geom_data;
	t_img	texNorth;
	// t_img	texSouth;
	// t_img	texEast;
	// t_img	texWest;
	
	int		floor_color;
	int		ceeling_color;

}	t_data;

void	geom_init(t_geom *geom_data);
int		create_trgb(int t, int r, int g, int b);
void	img_init(t_data *data, t_img *img_data, size_t width, size_t height);

int		red_cross();
void	move_forvard(t_geom *geom_data);
void	move_backward(t_geom *geom_data);
void	rotate_left(t_geom *geom_data);
void	rotate_right(t_geom *geom_data);
int		key_hook(int keycode, t_data *data);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	walls(t_geom *geom_data, t_img *img_data);
void 	floor_ceeling(t_img *img, int f_color, int c_color);
#endif