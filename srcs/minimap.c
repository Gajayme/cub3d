/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:55:57 by lyubov            #+#    #+#             */
/*   Updated: 2022/09/03 20:46:25 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/cub3d.h"

// extern int worldMap[mapHeight][mapWidth];

// void minimap_init(t_data *main_data)
// {
// 	main_data->geom_data.mini_map_width = maxMinimapSide;
// 	main_data->geom_data.mini_map_height = maxMinimapSide;
// 	if (main_data->geom_data.map_width < maxMinimapSide)
// 		main_data->geom_data.mini_map_width = main_data->geom_data.map_width;
// 	if (main_data->geom_data.map_height < maxMinimapSide)
// 		main_data->geom_data.mini_map_height = main_data->geom_data.map_height;
// 	main_data->geom_data.minimap_center_x = 0;
// 	main_data->geom_data.minimap_center_y = 0;
// 	img_init(main_data, &main_data->minimap_data, main_data->geom_data.mini_map_width * pixInMinimap,
// 			main_data->geom_data.mini_map_height * pixInMinimap);
//   	main_data->geom_data.mini_map_x = screenWidth - (main_data->geom_data.mini_map_width * pixInMinimap);
// 	main_data->geom_data.mini_map_y = 0;
// }

// //this should be use if map > max minimap size
// void minimap_center(t_data *main_data)
// {
// 	int player_x = main_data->geom_data.posX;
// 	int player_y = main_data->geom_data.posY;

// 	int map_width_idx = main_data->geom_data.map_width;
// 	int map_height_idx = main_data->geom_data.map_height;

// 	main_data->geom_data.minimap_center_x = player_x - minimapHalf;
// 	main_data->geom_data.minimap_center_y = player_y - minimapHalf;

// 	if (player_x >= (map_width_idx - minimapHalf))
// 		main_data->geom_data.minimap_center_x = (map_width_idx - maxMinimapSide);
// 	else if (player_x < minimapHalf)
// 		main_data->geom_data.minimap_center_x = 0;
// 	if (player_y >= (map_height_idx - minimapHalf))
// 		main_data->geom_data.minimap_center_y = (map_height_idx - maxMinimapSide);
// 	else if (player_y < minimapHalf)
// 		main_data->geom_data.minimap_center_y = 0;
// 	printf ("minimap center = %zu %zu\n", main_data->geom_data.minimap_center_x, main_data->geom_data.minimap_center_y );
// }

// void draw_rectangle(t_img *img_data, int x, int y, int width, int height, int color)
// {
// 	int i;
// 	int j;

// 	// x *= 10;
// 	// y *= 10;

// 	//printf("x = %d, y = %d\n", x, y);

// 	i = -1;
// 	while (++i < height){
// 		j = -1;
// 		while(++j < width){
// 			my_mlx_pixel_put(img_data, x + j, y + i, color);
// 		}
// 	}
// }

// void minimap_draw(t_data *main_data)
// {
// 	int j;
// 	int i;

// 	//int player_x = main_data->geom_data.posX;
// 	//int player_y = main_data->geom_data.posY;
// 	int start_x =  main_data->geom_data.minimap_center_x;
// 	int start_y =  main_data->geom_data.minimap_center_y;

// 	i = main_data->geom_data.minimap_center_y;
// 	while (i < start_y + maxMinimapSide){
// 		j = main_data->geom_data.minimap_center_x;
// 		while(j < start_x + maxMinimapSide){
// 			// CHECK!!!
// 			if (i > mapHeight || j > mapWidth){
// 				printf ("ERROR GO OVER MAP BORDERS IN DRAW MINIMAP\n");
// 				exit (1);
// 			}
// 			if (worldMap[i][j] == 1)
// 				draw_rectangle(&main_data->minimap_data , (j - start_x) * 10, (i - start_y) * 10, pixInMinimap, pixInMinimap, green);
// 			if (worldMap[i][j] == 9){
// 				draw_rectangle(&main_data->minimap_data , (j - start_x) * 10 + 3, (i - start_y) * 10 + 3, 4, 4, red);
// 				//draw_rectangle(&main_data->minimap_data , j - start_x, i - start_y, pixInMinimap, pixInMinimap, green);
// 			}
// 			++j;
// 		}
// 		++i;
// 	}
// }

// void minimap_update(t_data *main_data)
// {
// 	if (main_data->geom_data.map_width > maxMinimapSide || main_data->geom_data.map_height > maxMinimapSide)
//     	minimap_center(main_data);
//   	minimap_draw(main_data);
// 	raycast (main_data);
// 	mlx_put_image_to_window(main_data->mlx, main_data->mlx_win, main_data->minimap_data.img
// 			,main_data->geom_data.mini_map_x, main_data->geom_data.mini_map_y);
// }
