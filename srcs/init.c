/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:03:14 by georgii           #+#    #+#             */
/*   Updated: 2022/09/11 18:07:24 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void  img_init(t_data *data, t_img *img_data, size_t width, size_t height)
{

  img_data->img = mlx_new_image(data->mlx, width, height);
  if (!img_data->img)
  {
    ft_putstr_fd("img_init\n", 2);
    exit (1);
  }
  img_data->addr = mlx_get_data_addr(img_data->img, &img_data->bits_per_pixel, &img_data->line_length,
								&img_data->endian);
}

void geom_init(t_geom *geom_data)
{
  geom_data->posX = 22; //22
  geom_data->posY = 12; // 12
  geom_data->dirX = -1;
  geom_data->dirY = 0;
  geom_data->planeX = 0;
  geom_data->planeY = 0.66;
  geom_data->moveSpeed = 0;
  geom_data->rotSpeed = 0;
  geom_data->textureHeight = texHeight;
  geom_data->textureWidth = texWidth;
}

void texture_init(t_data *data){
    //north
    //img_init(data, &data->tex[1], data->geom_data.textureWidth, data->geom_data.textureHeight);
    data->tex[1].img = mlx_xpm_file_to_image(data->mlx, "textures/north.xpm", &data->geom_data.textureWidth, &data->geom_data.textureHeight);
    if (!data->tex[1].img){
        ft_putstr_fd("texture_init\n", 2);
        exit (1);
    }
    //mlx_put_image_to_window(data->mlx, data->mlx_win, data->tex[1].img, 0, 0);
    //south
    //img_init(data, &data->tex[0], data->geom_data.textureWidth, data->geom_data.textureHeight);
    data->tex[0].img = mlx_xpm_file_to_image(data->mlx, "textures/south.xpm", &data->geom_data.textureWidth, &data->geom_data.textureHeight);
    //int color = mlx_get_color_value(data->mlx, data->tex[0].addr[20]);
    //printf("color = %d\n", color);
    if (!data->tex[0].img){
        ft_putstr_fd("texture_init\n", 2);
        exit (1);
    }
    //mlx_put_image_to_window(data->mlx, data->mlx_win, data->tex[0].img, texWidth, 0);
    //west
    //img_init(data, &data->tex[3], data->geom_data.textureWidth, data->geom_data.textureHeight);
    data->tex[3].img = mlx_xpm_file_to_image(data->mlx, "textures/west.xpm", &data->geom_data.textureWidth, &data->geom_data.textureHeight);
    if (!data->tex[3].img){
        ft_putstr_fd("texture_init\n", 2);
        exit (1);
    }
    //mlx_put_image_to_window(data->mlx, data->mlx_win, data->tex[3].img, texWidth * 2, 0);
    //east
    //img_init(data, &data->tex[2], data->geom_data.textureWidth, data->geom_data.textureHeight);
    data->tex[2].img = mlx_xpm_file_to_image(data->mlx, "textures/east.xpm", &data->geom_data.textureWidth, &data->geom_data.textureHeight);
    if (!data->tex[2].img){
        ft_putstr_fd("texture_init\n", 2);
        exit (1);
    }
    //mlx_put_image_to_window(data->mlx, data->mlx_win, data->tex[2].img, texWidth * 3, 0);
}
