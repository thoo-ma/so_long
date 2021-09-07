/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:41:38 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 12:00:20 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->steps = 0;
	data->collectibles = 0;
	data->map.board = 0;
	init_my_strerror(data->my_strerror);
}

void	init_my_strerror(const char **my_strerror)
{
	my_strerror[MAIN_ARGS] = "so_long need one and only argument";
	my_strerror[MAP_MALLOC] = "map couldn't be malloced";
	my_strerror[MAP_RECTANGLE] = "map is not rectangle";
	my_strerror[MAP_NOT_CLOSE] = "map is not closed by walls";
	my_strerror[MAP_UNDEFINED] = "map contains undefined cells";
	my_strerror[MAP_NO_PLAYER] = "map has no player";
	my_strerror[MAP_EXTENSION] = "map is not a .ber file";
	my_strerror[MAP_MULT_PLAYERS] = "map contains multiple players";
	my_strerror[MAP_NO_COLLECTIBLES] = "map contains no collectibles";
	my_strerror[MAP_NO_EXIT] = "map contains no exit";
	my_strerror[MAP_LINES] = "map doesn't contains enough lines";
	my_strerror[MAP_IMG] = "mlx_new_image() failed";
	my_strerror[MAP_SIZE] = "so long too big : try reduce size of map or tiles";
	my_strerror[MAP_OPEN] = "cannot open map";
	my_strerror[MAP_READ] = "unable to read map file content";
	my_strerror[MAP_ENOENT] = "map : no such file or directory";
	my_strerror[MAP_EACCES] = "map : permission denied";
	my_strerror[MAP_EISDIR] = "map is a directory";
	my_strerror[MLX_WINDOW] = "mlx_new_window() failed";
	my_strerror[MLX_INIT] = "mlx_init() failed";
	my_strerror[XPM_FILE] = "mlx_xpm_file_to_image() failed";
}

void	init_so_long(t_data *data)
{
	get_mlx_instance(data);
	get_mlx_window(data);
	get_mlx_images(data);
}
