/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgii <georgii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:10:56 by lyubov            #+#    #+#             */
/*   Updated: 2022/09/04 17:07:39 by georgii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	red_cross()
{
	//memory free
	exit (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13)
		move_forward(&data->geom_data);
	if (keycode == 1)
		move_backward(&data->geom_data);
	if (keycode == 0)
	 	rotate_left(&data->geom_data);
	if (keycode == 2)
	 	rotate_right(&data->geom_data);
	if (keycode == 53) // < memory free
		exit (0);
	return (0);
}
