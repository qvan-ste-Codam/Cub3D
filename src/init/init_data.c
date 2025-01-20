/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 21:50:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/22 15:08:34 by qvan-ste      ########   odam.nl         */
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
	player->pos_x = player_x;
	player->pos_y = player_y;
	return (player);
}

static t_camera	*init_camera(int view_direction_x, int view_direction_y)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
	{
		return (NULL);
	}
	camera->plane_x = 0;
	camera->plane_y = 0.66;
	camera->view_dir_x = view_direction_x;
	camera->view_dir_y = view_direction_y;
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
	game->player = init_player(3, 4);
	if (!game->player)
		return (FAILURE);
	game->camera = init_camera(-1, 0);
	if (!game->camera)
		return (FAILURE);
	game->display = init_display(texture_paths, rgb_floor, rgb_ceiling);
	if (!game->display)
		return (FAILURE);
	return (SUCCESS);
}
