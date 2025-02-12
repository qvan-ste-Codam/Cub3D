/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:50:19 by qvan-ste          #+#    #+#             */
/*   Updated: 2025/02/12 14:28:21 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <stdlib.h>

static void	set_camera_plane(int direction, t_camera *camera)
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
	game->player = init_player(9, 4);
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
