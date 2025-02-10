/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 21:50:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/02/10 16:38:54 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <stdlib.h>

static t_player	*init_player(int player_x, int player_y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		return (NULL);
	}
	player->pos_x = player_x + 0.5;
	player->pos_y = player_y + 0.5;
	return (player);
}

static void	set_view_direction(int direction, t_camera	*camera)
{
	if (direction == WEST)
	{
		camera->plane_x = 0;
		camera->plane_y = 0.66;
	}
	else if (direction == EAST)
	{
		camera->plane_x = 0;
		camera->plane_y = -0.66;
	}
	else if (direction == NORTH)
	{
		camera->plane_x = -0.66;
		camera->plane_y = 0;
	}
	else if (direction == SOUTH)
	{
		camera->plane_x = 0.66;
		camera->plane_y = 0;
	}
}

static t_camera	*init_camera(int view_direction_x, int view_direction_y)
{
	t_camera	*camera;
	int			direction;

	camera = malloc(sizeof(t_camera));
	if (!camera)
	{
		return (NULL);
	}
	camera->view_dir_x = view_direction_x;
	camera->view_dir_y = view_direction_y;
	if (view_direction_x == -1 && view_direction_y == 0)
		direction = WEST;
	else if (view_direction_x == 1 && view_direction_y == 0)
		direction = EAST;
	else if (view_direction_x == 0 && view_direction_y == -1)
		direction = NORTH;
	else
		direction = SOUTH;
	set_view_direction(direction, camera);
	return (camera);
}

int	init_data(t_data *game, char *map_file)
{
	static char	*texture_paths[] = {
		"textures/north.png",
		"textures/south.png",
		"textures/east.png",
		"textures/west.png",
		NULL
	};
	static int	rgb_floor[3] = {3, 252, 177};
	static int	rgb_ceiling[3] = {252, 3, 240};

	game->map = create_map(map_file);
	if (!game->map)
		return (FAILURE);
	game->player = init_player(9, 4);
	if (!game->player)
		return (FAILURE);
	game->camera = init_camera(0, 1);
	if (!game->camera)
		return (FAILURE);
	game->display = init_display(texture_paths, rgb_floor, rgb_ceiling);
	if (!game->display)
		return (FAILURE);
	return (SUCCESS);
}
