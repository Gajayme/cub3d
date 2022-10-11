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
    data->north_tex->img = mlx_xpm_file_to_image(data->mlx, "textures/north.xpm", &data->geom_data.textureWidth, &data->geom_data.textureHeight);
    data->north_tex->addr = (int *)mlx_get_data_addr(data->north_tex->img,
                                          &data->north_tex->bits_per_pixel, &data->north_tex->line_length,
                                          &data->north_tex->endian);
    if (!data->north_tex->img){
        ft_putstr_fd("texture_init\n", 2);
        exit (1);
    }

//    int color = get_tex_color(data->north_tex, 1, 1);
//    my_mlx_pixel_put(data->north_tex, 30, 30, color);
//    my_mlx_pixel_put(data->north_tex, 31, 30, color);
//    my_mlx_pixel_put(data->north_tex, 32, 30, color);
//    my_mlx_pixel_put(data->north_tex, 33, 30, color);
//    my_mlx_pixel_put(data->north_tex, 34, 30, color);
//    my_mlx_pixel_put(data->north_tex, 35, 30, color);
//    mlx_put_image_to_window(data->mlx, data->mlx_win, data->north_tex->img, 0, 0);
}

