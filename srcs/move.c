/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:53:09 by georgii           #+#    #+#             */
/*   Updated: 2022/09/04 17:07:19 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include <math.h>

extern int worldMap[mapWidth][mapHeight];


void move_forward(t_geom *geom_data)
{   
    if(worldMap[(int)(geom_data->posX + geom_data->dirX * geom_data->moveSpeed)][(int)geom_data->posY] ==  0)
    {    
        geom_data->posX += geom_data->dirX * geom_data->moveSpeed;
    }
    if(worldMap[(int)geom_data->posX][(int)(geom_data->posY + geom_data->dirY * geom_data->moveSpeed)] == 0) 
    {
        geom_data->posY += geom_data->dirY * geom_data->moveSpeed;
        
    }
}

void move_backward(t_geom *geom_data)
{
    if(worldMap[(int)(geom_data->posX - geom_data->dirX * geom_data->moveSpeed)][(int)geom_data->posY] == 0)
    {
        geom_data->posX -= geom_data->dirX * geom_data->moveSpeed;
    }
    if(worldMap[(int)geom_data->posX][(int)(geom_data->posY - geom_data->dirY * geom_data->moveSpeed)] == 0)
    {
        geom_data->posY -= geom_data->dirY * geom_data->moveSpeed;    
    }    
}

void rotate_left(t_geom *geom_data)
{
    double oldDirX = geom_data->dirX;
    geom_data->dirX = geom_data->dirX * cos(geom_data->rotSpeed) - geom_data->dirY * sin(geom_data->rotSpeed);
    geom_data->dirY = oldDirX * sin(geom_data->rotSpeed) + geom_data->dirY * cos(geom_data->rotSpeed);
    double oldPlaneX = geom_data->planeX;
    geom_data->planeX = geom_data->planeX * cos(geom_data->rotSpeed) - geom_data->planeY * sin(geom_data->rotSpeed);
    geom_data->planeY = oldPlaneX * sin(geom_data->rotSpeed) + geom_data->planeY * cos(geom_data->rotSpeed);    
}

void rotate_right(t_geom *geom_data)
{
    double oldDirX = geom_data->dirX;
    geom_data->dirX = geom_data->dirX * cos(-geom_data->rotSpeed) - geom_data->dirY * sin(-geom_data->rotSpeed);
    geom_data->dirY = oldDirX * sin(-geom_data->rotSpeed) + geom_data->dirY * cos(-geom_data->rotSpeed);
    double oldPlaneX = geom_data->planeX;
    geom_data->planeX = geom_data->planeX * cos(-geom_data->rotSpeed) - geom_data->planeY * sin(-geom_data->rotSpeed);
    geom_data->planeY = oldPlaneX * sin(-geom_data->rotSpeed) + geom_data->planeY * cos(-geom_data->rotSpeed);
    
}
