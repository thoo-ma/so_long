/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:42:23 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 12:03:03 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "X11/X.h"
# include "mlx.h"
# include "gnl.h"
# include "libft.h"

/******************************************************************************/
/*                                                                            */
/*		map elements                                                          */
/*                                                                            */
/******************************************************************************/

# define SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define PLAYER 'P'
# define COLLECTIBLE 'C'

/******************************************************************************/
/*                                                                            */
/*		tiles dimensions                                                      */
/*                                                                            */
/******************************************************************************/

# define TILE_X 32
# define TILE_Y 32

/******************************************************************************/
/*                                                                            */
/*		keycodes                                                              */
/*                                                                            */
/******************************************************************************/

# define A 97
# define S 115
# define D 100
# define W 119
# define ESC 65307

/******************************************************************************/
/*                                                                            */
/*		errors / exit values                                                  */
/*                                                                            */
/******************************************************************************/

typedef enum e_errno
{
	ZERO,
	MAIN_ARGS,
	MAP_MALLOC,
	MAP_RECTANGLE,
	MAP_NOT_CLOSE,
	MAP_UNDEFINED,
	MAP_NO_PLAYER,
	MAP_EXTENSION,
	MAP_MULT_PLAYERS,
	MAP_NO_COLLECTIBLES,
	MAP_NO_EXIT,
	MAP_LINES,
	MAP_IMG,
	MAP_SIZE,
	MAP_OPEN,
	MAP_READ,
	MAP_ENOENT,
	MAP_EACCES,
	MAP_EISDIR,
	MLX_WINDOW,
	MLX_INIT,
	XPM_FILE,
	ERRORS
}			t_errno;

/******************************************************************************/
/*                                                                            */
/*		position vector (2D)                                                  */
/*                                                                            */
/******************************************************************************/

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

/******************************************************************************/
/*                                                                            */
/*		all mlx image's useful data in one place                              */
/*                                                                            */
/******************************************************************************/

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		ll;
	int		bpp;
	int		endian;
}				t_img;

/******************************************************************************/
/*                                                                            */
/*		all data related to the map (except its mlx image)                    */
/*                                                                            */
/******************************************************************************/

typedef struct s_map
{
	char	**board;
	t_pos	player;
	t_pos	dimensions;
}				t_map;

/******************************************************************************/
/*                                                                            */
/*		all mlx images so_long uses                                           */
/*                                                                            */
/******************************************************************************/

typedef struct s_images
{
	t_img	map;
	t_img	exit;
	t_img	wall;
	t_img	space;
	t_img	player;
	t_img	collectible;
}				t_images;

/******************************************************************************/
/*                                                                            */
/*		all structs and enums defined above plus :                            */
/*                                                                            */
/*			- mlx instance                                                    */
/*			- mlx window                                                      */
/*			- all error messages                                              */
/*			- real-time count of remaining collectibles                       */
/*			- real-time count of steps done by the player                     */
/*                                                                            */
/******************************************************************************/

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_images	images;
	const char	*my_strerror[ERRORS + 1];
	int			steps;
	int			collectibles;
}				t_data;

/******************************************************************************/
/*                                                                            */
/*		gfx.c                                                                 */
/*                                                                            */
/******************************************************************************/

void	tile_to_map(t_data *data, t_img *tile, int x, int y);
void	fill_map_image(t_data *data);
void	get_map_image(t_data *data);
void	*get_xpm_image(t_data *data, char *filename);
void	get_mlx_images(t_data *data);

/******************************************************************************/
/*                                                                            */
/*		hook.c                                                                */
/*                                                                            */
/******************************************************************************/

int		display_map(t_data *data);
int		key_handler(int key, t_data *data);
void	define_hooks(t_data *data);

/******************************************************************************/
/*                                                                            */
/*		init.c                                                                */
/*                                                                            */
/******************************************************************************/

void	init_data(t_data *data);
void	init_so_long(t_data *data);
void	init_my_strerror(const char **my_strerror);

/******************************************************************************/
/*                                                                            */
/*		utils.c                                                               */
/*                                                                            */
/******************************************************************************/

void	get_mlx_instance(t_data *data);
void	get_mlx_window(t_data *data);
void	get_map_dimensions(t_data *data);
void	free_so_long(t_data *data);
void	exit_so_long(t_data *data, t_errno my_errno);

/******************************************************************************/
/*                                                                            */
/*		array.c                                                               */
/*                                                                            */
/******************************************************************************/

void	free_2d_array(char **a);
int		length_2d_array(char **a);
int		elem_index(char *s, char c);

/******************************************************************************/
/*                                                                            */
/*		move.c                                                                */
/*                                                                            */
/******************************************************************************/

int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
void	move_exit(t_data *data);

/******************************************************************************/
/*                                                                            */
/*		parse.c                                                               */
/*                                                                            */
/******************************************************************************/

int		get_map_rows(t_data *data, int fd, char c);
int		open_map(char *filename, t_data *data);
void	get_map(t_data *data, char *filename);
void	parse(char *filename, t_data *data);

/******************************************************************************/
/*                                                                            */
/*		check1.c                                                              */
/*                                                                            */
/******************************************************************************/

void	check_rectangle(t_data *data, char **map);
void	check_map_close(t_data *data, char **map);
void	check_undefined(t_data *data, char **map);
void	check_exits(t_data *data, char **map);
void	check_collectibles(t_data *data, char **map);

/******************************************************************************/
/*                                                                            */
/*		check2.c                                                              */
/*                                                                            */
/******************************************************************************/

void	check_map_size(t_data *data);
void	check_map(t_data *data, char **map);
void	check_player(t_data *data, char **map);
void	check_file_extension(t_data *data, char *filename);

#endif
