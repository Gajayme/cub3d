/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:03:14 by georgii           #+#    #+#             */
/*   Updated: 2022/09/07 20:25:18 by georgii          ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void geom_init(t_geom *geom_data)
{
  geom_data->posX = 22;
  geom_data->posY = 12;
  geom_data->dirX = -1;
  geom_data->dirY = 0;
  geom_data->planeX = 0;
  geom_data->planeY = 0.66;
  geom_data->moveSpeed = 0;
  geom_data->rotSpeed = 0;
}  

