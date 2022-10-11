/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:56:13 by lyubov            #+#    #+#             */
/*   Updated: 2022/09/11 18:26:54 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <time.h>

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//0
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//1
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
  {1,2,2,2,3,0,0,0,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},//4
  {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
  {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},//6
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},//7
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},//8
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//9
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//11
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//12
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//13
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//14
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//15
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//16
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//17
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//18
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//19
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//20
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//21
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//22
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}//23
};

//size_t buffer[screenHeight][screenWidth];

int	render_next_frame(t_data *data)
{   
  clock_t start_t;
  start_t = clock(); 

  img_init(data, &data->img_data, screenWidth, screenHeight);
  floor_ceiling(&data->img_data, data->floor_color, data->ceiling_color);
  walls(data, &data->geom_data, &data->img_data);
  
  double frameTime = (clock() - start_t);
  double frameTimeSec =  frameTime / CLOCKS_PER_SEC;
  //printf("frame was drawn in : %f sec\n", frameTimeSec);
  //printf("fps =  : %f ms\n", 1 / frameTimeSec);
  data->geom_data.moveSpeed = frameTimeSec * 150; //the constant value is in squares/second
  data->geom_data.rotSpeed = frameTimeSec * 100; //the constant value is in radians/second 
  
  mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_data.img, 0, 0);
  mlx_destroy_image(data->mlx, data->img_data.img);
  return (0);
  
}

int main()
{
  t_data	data;  

  data.mlx = mlx_init();
  
  data.ceiling_color = create_trgb(0, 1, 1, 100);
  data.floor_color = create_trgb(0, 100, 100, 100);
  
  data.mlx_win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Cub3D");
  geom_init(&data.geom_data);

  texture_init(&data);

  mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
  mlx_hook(data.mlx_win, 17, 0, red_cross, &data);
  mlx_loop_hook(data.mlx, render_next_frame, &data);
  mlx_loop(data.mlx);
  return (0);
}

