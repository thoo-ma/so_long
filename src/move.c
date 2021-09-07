/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:04:21 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 08:23:35 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_exit(t_data *data)
{
	if (data->collectibles == 0)
	{
		printf("%d\n", ++data->steps);
		exit_so_long(data, 0);
	}
	else
		printf("Cannot exit: remain collectibles !\n");
}

int	move_left(t_data *data)
{
	char	*dst;

	dst = &data->map.board[data->map.player.y][data->map.player.x - 1];
	if (*dst == EXIT)
		move_exit(data);
	else if (*dst != WALL)
	{
		if (*dst == COLLECTIBLE)
		{
			*dst = SPACE;
			data->collectibles--;
		}
		tile_to_map(data, &data->images.space,
			data->map.player.y,
			data->map.player.x);
		tile_to_map(data, &data->images.player,
			data->map.player.y,
			data->map.player.x - 1);
		data->map.player.x--;
		data->steps++;
		return (1);
	}
	return (0);
}

int	move_right(t_data *data)
{
	char	*dst;

	dst = &data->map.board[data->map.player.y][data->map.player.x + 1];
	if (*dst == EXIT)
		move_exit(data);
	else if (*dst != WALL)
	{
		if (*dst == COLLECTIBLE)
		{
			*dst = SPACE;
			data->collectibles--;
		}
		tile_to_map(data, &data->images.space,
			data->map.player.y,
			data->map.player.x);
		tile_to_map(data, &data->images.player,
			data->map.player.y,
			data->map.player.x + 1);
		data->map.player.x++;
		data->steps++;
		return (1);
	}
	return (0);
}

int	move_up(t_data *data)
{
	char	*dst;

	dst = &data->map.board[data->map.player.y - 1][data->map.player.x];
	if (*dst == EXIT)
		move_exit(data);
	else if (*dst != WALL)
	{
		if (*dst == COLLECTIBLE)
		{
			*dst = SPACE;
			data->collectibles--;
		}
		tile_to_map(data, &data->images.space,
			data->map.player.y,
			data->map.player.x);
		tile_to_map(data, &data->images.player,
			data->map.player.y - 1,
			data->map.player.x);
		data->map.player.y--;
		data->steps++;
		return (1);
	}
	return (0);
}

int	move_down(t_data *data)
{
	char	*dst;

	dst = &data->map.board[data->map.player.y + 1][data->map.player.x];
	if (*dst == EXIT)
		move_exit(data);
	else if (*dst != WALL)
	{
		if (*dst == COLLECTIBLE)
		{
			*dst = SPACE;
			data->collectibles--;
		}
		tile_to_map(data, &data->images.space,
			data->map.player.y,
			data->map.player.x);
		tile_to_map(data, &data->images.player,
			data->map.player.y + 1,
			data->map.player.x);
		data->map.player.y++;
		data->steps++;
		return (1);
	}
	return (0);
}
