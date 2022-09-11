/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:52:09 by georgii           #+#    #+#             */
/*   Updated: 2022/09/11 15:56:31 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include <math.h>

extern int worldMap[mapWidth][mapHeight];

void  vertical_line(t_img *img, int x, int y_low, int y_high, int color)
{
  for (int i = y_low; i <= y_high; ++i){
    my_mlx_pixel_put(img, x, i, color);
  }
}

void floor_ceeling(t_img *img, int f_color, int c_color)
{
  int height;
  int width;
  int half_screen;
  
  height = 0;
  half_screen = screenHeight / 2;
  
  while (height < screenHeight)
  {
    width = 0;
    while (width < screenWidth)
    {
      if (height < half_screen)
        my_mlx_pixel_put(img, width, height, c_color);
      else 
        my_mlx_pixel_put(img, width, height, f_color);
    width ++;
    }
    height ++;    
  } 
}

void color_picker(int *color, int side, double rayDirX, double rayDirY){
  if (side == 0){
    if (rayDirX >= 0)
      *color = red;
    else
     *color = blue;
    return;
  }
  if (rayDirY > 0 )
    *color = yellow;
  else
    *color = green;
  
}

void walls (t_geom *geom_data, t_img *img_data)
{
    for(int x = 0; x < screenWidth; x++)
    {
        //calculate ray position and direction
        double cameraX = 2 * (x / (double)screenWidth) - 1; //x-coordinate in camera space
        double rayDirX = geom_data->dirX + geom_data->planeX * cameraX;
        double rayDirY = geom_data->dirY + geom_data->planeY * cameraX;
        //which box of the map we're in
        int mapX = (int)geom_data->posX;
        int mapY = (int)geom_data->posY;    
        //length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;
    
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
    
        double perpWallDist;
    
        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;
    
        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit? 0 - x 1 - y
        //calculate step and initial sideDist
        if(rayDirX < 0)
        {
          stepX = -1;
          sideDistX = (geom_data->posX - mapX) * deltaDistX;
        }
        else
        {
          stepX = 1;
          sideDistX = (mapX + 1.0 - geom_data->posX) * deltaDistX;
        }
        if(rayDirY < 0)
        {
          stepY = -1;
          sideDistY = (geom_data->posY - mapY) * deltaDistY;
        }
        else
        {
          stepY = 1;
          sideDistY = (mapY + 1.0 - geom_data->posY) * deltaDistY;
        }
        //perform DDA
        while(hit == 0)
        {
          //jump to next map square, either in x-direction, or in y-direction
          if(sideDistX < sideDistY)
          {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
          }
          else
          {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
          }
          //Check if ray has hit a wall
          if(worldMap[mapX][mapY] > 0) hit = 1;
        }
        if(side == 0) perpWallDist = (sideDistX - deltaDistX);
        else          perpWallDist = (sideDistY - deltaDistY);
    
        //Calculate height of line to draw on screen
        int lineHeight = (int)(screenHeight / perpWallDist);
    
        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if(drawEnd >= screenHeight) drawEnd = screenHeight - 1;
    
        //choose wall color
        int color;
        color_picker(&color, side, rayDirX, rayDirY);
        
        // if (side == 0){
        //   if (rayDirX >= 0){
        //     color = red;
        //   } else {
        //     color = blue
        //   }
        // }
        
        // if (rayDirX >= 0){
        //   if (side == 0)
        //     color = red;
        //   else {
        //     if (rayDirY > 0 )
        //       color = yellow;
        //     else
        //       color = green;
        //   }
        // } else{
        //   if (side == 0)
        //     color = blue;
        //   else{
        //     if (rayDirY > 0 )
        //       color = yellow;
        //     else
        //       color = green;
        //   }
        // }     
        // switch(worldMap[mapX][mapY])
        // {
        //     case 1:  color = red;    break; //red
        //     case 2:  color = green;  break; //green
        //     case 3:  color = blue;   break; //blue
        //     case 4:  color = white;  break; //white
        //     default: color = yellow; break; //yellow
        // }
        // if (side == 1)
        // {
        //   color /= 2; 
        // }
        vertical_line(img_data, x, drawStart, drawEnd, color);
  } 
}