/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:41:44 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 10:35:20 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tile_to_map(t_data *data, t_img *tile, int y, int x)
{
	int		i;

	data->images.map.addr = mlx_get_data_addr(data->images.map.img,
			&data->images.map.bpp,
			&data->images.map.ll,
			&data->images.map.endian);
	tile->addr = mlx_get_data_addr(tile->img,
			&tile->bpp,
			&tile->ll,
			&tile->endian);
	i = 0;
	while (i < TILE_Y)
	{
		ft_memcpy(data->images.map.addr + \
			y * TILE_Y * 4 * data->map.dimensions.x + \
			i * data->map.dimensions.x * 4 + \
			x * TILE_X * 4,
			tile->addr + \
			i * TILE_Y * 4,
			TILE_Y * 4);
		i++;
	}
}

void	fill_map_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.board[i])
	{
		j = 0;
		while (data->map.board[i][j])
		{
			if (data->map.board[i][j] == WALL)
				tile_to_map(data, &data->images.wall, i, j);
			else if (data->map.board[i][j] == EXIT)
				tile_to_map(data, &data->images.exit, i, j);
			else if (data->map.board[i][j] == SPACE)
				tile_to_map(data, &data->images.space, i, j);
			else if (data->map.board[i][j] == PLAYER)
				tile_to_map(data, &data->images.player, i, j);
			else if (data->map.board[i][j] == COLLECTIBLE)
				tile_to_map(data, &data->images.collectible, i, j);
			j++;
		}
		i++;
	}
}

void	get_map_image(t_data *data)
{
	data->images.map.img = mlx_new_image(data->mlx,
			data->map.dimensions.x,
			data->map.dimensions.y);
	if (data->images.map.img == 0)
		exit_so_long(data, MAP_IMG);
	fill_map_image(data);
}

void	*get_xpm_image(t_data *data, char *filename)
{
	int		x;
	int		y;
	void	*image;

	image = 0;
	image = mlx_xpm_file_to_image(data->mlx, filename, &x, &y);
	if (image == 0)
		exit_so_long(data, XPM_FILE);
	return (image);
}

void	get_mlx_images(t_data *data)
{
	data->images.exit.img = get_xpm_image(data, "assets/exit.xpm");
	data->images.wall.img = get_xpm_image(data, "assets/tree.xpm");
	data->images.space.img = get_xpm_image(data, "assets/grass.xpm");
	data->images.player.img = get_xpm_image(data, "assets/hacker.xpm");
	data->images.collectible.img = get_xpm_image(data, "assets/btc.xpm");
	get_map_image(data);
}
