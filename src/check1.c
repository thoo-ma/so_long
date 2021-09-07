/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 07:32:49 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 11:48:18 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(t_data *data, char **map)
{
	int		i;

	i = 0;
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
		{
			exit_so_long(data, MAP_RECTANGLE);
		}
		i++;
	}
}

void	check_map_close(t_data *data, char **map)
{
	int	i;
	int	len;

	len = length_2d_array(map);
	if (ft_strcspn(map[0], "1"))
	{
		exit_so_long(data, MAP_NOT_CLOSE);
	}
	if (ft_strcspn(map[len - 1], "1"))
	{
		exit_so_long(data, MAP_NOT_CLOSE);
	}
	i = 1;
	while (i < len)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			exit_so_long(data, MAP_NOT_CLOSE);
		}
		i++;
	}
}

void	check_undefined(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strcspn(map[i], "01EPC"))
		{
			exit_so_long(data, MAP_UNDEFINED);
		}
		i++;
	}
}

void	check_collectibles(t_data *data, char **map)
{
	int		i;
	int		j;
	int		item;

	i = 0;
	item = 0;
	while (map[i])
	{
		item = elem_index(map[i], COLLECTIBLE);
		j = 0;
		while (item > -1)
		{
			data->collectibles++;
			j += item + 1;
			item = elem_index(map[i] + j, COLLECTIBLE);
		}
		i++;
	}
	if (data->collectibles == 0)
	{
		exit_so_long(data, MAP_NO_COLLECTIBLES);
	}
}

void	check_exits(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (elem_index(map[i], EXIT) > -1)
			return ;
		i++;
	}
	exit_so_long(data, MAP_NO_EXIT);
}
