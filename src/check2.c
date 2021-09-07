/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 07:33:37 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 09:58:05 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_extension(t_data *data, char *filename)
{
	size_t	len;

	len = 0;
	len = ft_strlen(filename);
	if (len < 5 || ft_strcmp(&filename[len - 4], ".ber"))
	{
		exit_so_long(data, MAP_EXTENSION);
	}
}

void	check_player(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = elem_index(map[y], 'P');
		if (x > -1)
		{
			data->map.player.x = x;
			data->map.player.y = y;
			if (elem_index(map[y] + x + 1, 'P') > -1)
				exit_so_long(data, MAP_MULT_PLAYERS);
			while (map[++y])
			{
				if (elem_index(map[y], 'P') > -1)
					exit_so_long(data, MAP_MULT_PLAYERS);
			}
			return ;
		}
		y++;
	}
	exit_so_long(data, MAP_NO_PLAYER);
}

void	check_map_size(t_data *data)
{
	void	*mlx;
	int		x;
	int		y;

	get_map_dimensions(data);
	mlx = 0;
	mlx = mlx_init();
	if (mlx == 0)
		exit_so_long(data, 0);
	mlx_get_screen_size(mlx, &x, &y);
	mlx_destroy_display(mlx);
	free(mlx);
	if (data->map.dimensions.x > x || data->map.dimensions.y > y)
	{
		exit_so_long(data, MAP_SIZE);
	}
}

void	check_map(t_data *data, char **map)
{
	check_map_size(data);
	check_rectangle(data, map);
	check_map_close(data, map);
	check_undefined(data, map);
	check_exits(data, map);
	check_collectibles(data, map);
	check_player(data, map);
}
