/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:42:17 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 09:51:58 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_so_long(t_data *data)
{
	if (data)
	{
		if (data->map.board)
			free_2d_array(data->map.board);
		if (data->mlx)
		{
			if (data->images.map.img)
				mlx_destroy_image(data->mlx, data->images.map.img);
			if (data->images.exit.img)
				mlx_destroy_image(data->mlx, data->images.exit.img);
			if (data->images.wall.img)
				mlx_destroy_image(data->mlx, data->images.wall.img);
			if (data->images.space.img)
				mlx_destroy_image(data->mlx, data->images.space.img);
			if (data->images.player.img)
				mlx_destroy_image(data->mlx, data->images.player.img);
			if (data->images.collectible.img)
				mlx_destroy_image(data->mlx, data->images.collectible.img);
			if (data->win)
				mlx_destroy_window(data->mlx, data->win);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
	}
}

void	exit_so_long(t_data *data, t_errno my_errno)
{
	free_so_long(data);
	if (my_errno)
	{
		write(2, "Error: ", 7);
		write(2,
			data->my_strerror[my_errno],
			ft_strlen(data->my_strerror[my_errno]));
		write(2, "\n", 1);
	}
	exit(my_errno);
}

void	get_map_dimensions(t_data *data)
{
	data->map.dimensions.x = TILE_X * ft_strlen(data->map.board[0]);
	data->map.dimensions.y = TILE_Y * length_2d_array(data->map.board);
}

void	get_mlx_instance(t_data *data)
{
	data->mlx = 0;
	data->mlx = mlx_init();
	if (data->mlx == 0)
		exit_so_long(data, MLX_INIT);
}

void	get_mlx_window(t_data *data)
{
	data->win = 0;
	data->win = mlx_new_window(data->mlx,
			data->map.dimensions.x,
			data->map.dimensions.y,
			"SO LONG");
	if (data->win == 0)
		exit_so_long(data, MLX_WINDOW);
}
