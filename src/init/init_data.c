/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tgoossen <tgoossen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 21:50:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/02/12 17:03:19 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <stdlib.h>

static void	set_camera_plane(int direction, t_camera *camera)
{
	if (direction == NORTH)
	{
		camera->plane_x = 0;
		camera->plane_y = 0.66;
	}
	else if (direction == SOUTH)
	{
		camera->plane_x = 0;
		camera->plane_y = -0.66;
	}
	else if (direction == EAST)
	{
		camera->plane_x = 0.66;
		camera->plane_y = 0;
	}
	else if (direction == WEST)
	{
		camera->plane_x = -0.66;
		camera->plane_y = 0;
	}
}

static void	set_view_direction(int direction, t_camera *camera)
{
	if (direction == NORTH)
	{
		camera->view_dir_x = -1;
		camera->view_dir_y = 0;
	}
	else if (direction == SOUTH)
	{
		camera->view_dir_x = 1;
		camera->view_dir_y = 0;
	}
	else if (direction == EAST)
	{
		camera->view_dir_x = 0;
		camera->view_dir_y = 1;
	}
	else if (direction == WEST)
	{
		camera->view_dir_x = 0;
		camera->view_dir_y = -1;
	}
}

static t_camera	*init_camera(t_parse_data *parse_data)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
	{
		return (NULL);
	}
	set_view_direction(parse_data->view_direction, camera);
	set_camera_plane(parse_data->view_direction, camera);
	return (camera);
}

static void	init_texture_paths(t_parse_data *map_data)
{
	map_data->texture_paths[NORTH] = map_data->no_texture;
	map_data->texture_paths[SOUTH] = map_data->so_texture;
	map_data->texture_paths[WEST] = map_data->we_texture;
	map_data->texture_paths[EAST] = map_data->ea_texture;
}

int	init_data(t_data *game, char *map_file)
{
	t_parse_data	*parse_data;

	parse_data = malloc(sizeof(t_parse_data));
	game->map = create_map(map_file, parse_data);
	if (!game->map)
		return (FAILURE);
	if (init_parse_data(parse_data) != SUCCESS)
		return (FAILURE);
	init_texture_paths(parse_data);
	game->player = init_player(parse_data->start_pos_x,
			parse_data->start_pos_y);
	if (!game->player)
		return (FAILURE);
	game->camera = init_camera(parse_data);
	if (!game->camera)
		return (FAILURE);
	game->display = init_display(parse_data);
	if (!game->display)
		return (FAILURE);
	free_init(parse_data);
	return (SUCCESS);
}
