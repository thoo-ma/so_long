/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:41:57 by trobin            #+#    #+#             */
/*   Updated: 2021/09/06 13:41:58 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_map(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images.map.img, 0, 0);
	return (0);
}

int	key_handler(int key, t_data *data)
{
	int	move;

	move = 0;
	if (key == ESC)
		mlx_loop_end(data->mlx);
	else if (key == A)
		move = move_left(data);
	else if (key == D)
		move = move_right(data);
	else if (key == W)
		move = move_up(data);
	else if (key == S)
		move = move_down(data);
	if (move)
	{
		printf("%d\n", data->steps);
		return (display_map(data));
	}
	return (1);
}

void	define_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_handler, data);
	mlx_hook(data->win, ClientMessage, GCClipXOrigin, &mlx_loop_end, data->mlx);
	mlx_loop_hook(data->mlx, &display_map, data);
	mlx_loop(data->mlx);
}
