/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:42:12 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 12:04:08 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_rows(t_data *data, int fd, char c)
{
	char	d;
	int		n;
	int		ret;

	n = 0;
	ret = read(fd, &d, 1);
	while (ret > 0)
	{
		if (c == d)
			n++;
		ret = read(fd, &d, 1);
	}
	if (ret == -1)
	{
		if (errno == EISDIR)
			exit_so_long(data, MAP_EISDIR);
		else
			exit_so_long(data, MAP_READ);
	}
	if (d != '\n')
		n++;
	return (n);
}

int	open_map(char *file, t_data *data)
{
	int	fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			exit_so_long(data, MAP_ENOENT);
		else if (errno == EACCES)
			exit_so_long(data, MAP_EACCES);
		else
			exit_so_long(data, MAP_OPEN);
	}
	return (fd);
}

void	get_map(t_data *data, char *filename)
{
	int	i;
	int	fd;
	int	lf;

	fd = open_map(filename, data);
	lf = get_map_rows(data, fd, '\n');
	close(fd);
	if (lf < 2)
	{
		exit_so_long(data, MAP_LINES);
	}
	data->map.board = 0;
	data->map.board = malloc(sizeof(char *) * (lf + 1));
	if (data->map.board == 0)
	{
		exit_so_long(data, MAP_MALLOC);
	}
	fd = open_map(filename, data);
	i = 0;
	while (i < lf)
	{
		get_next_line(fd, &data->map.board[i++]);
	}
	data->map.board[i] = 0;
	close(fd);
}

void	parse(char *filename, t_data *data)
{
	check_file_extension(data, filename);
	get_map(data, filename);
	check_map(data, data->map.board);
}
