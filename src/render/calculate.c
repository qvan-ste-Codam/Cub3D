/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 19:16:00 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 21:25:42 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>

#define X 0
#define Y 1

static void	calculate_delta_distance(
	t_line *line, t_camera *camera, double camera_x)
{
	double	ray_direction_x;
	double	ray_direction_y;

	ray_direction_x = camera -> view_dir[X] + camera -> plane[X] * camera_x;
	ray_direction_y = camera -> view_dir[Y] + camera -> plane[Y] * camera_x;
	line -> delta_distance[X] = fabs(1 / ray_direction_x);
	line -> delta_distance[Y] = fabs(1 / ray_direction_y);
}

static void	calculate_line_distance(t_line *line, t_player *player)
{
	if (line -> ray_direction[X] < 0)
	{
		line->step[X] = -1;
		line->side_distance[X] = (player->position[X] - line->position[X])
			* line->delta_distance[X];
	}
	else
	{
		line->step[Y] = 1;
		line->side_distance[X]
			= (player->position[X] + 1 - player->position[X])
			* line->delta_distance[X];
	}
	if (line -> ray_direction[Y] < 0)
	{
		line->step[X] = -1;
		line->side_distance[Y] = (player->position[Y] - line->position[Y])
			* line->delta_distance[X];
	}
	else
	{
		line->step[Y] = 1;
		line->side_distance[Y] = (player->position[Y] + 1 - player->position[Y])
			* line->delta_distance[Y];
	}
}

static void	calculate_wall_distance(t_line *line, char **map)
{
	bool	hit;
	int		side;

	hit = false;
	while (hit == false)
	{
		if (line -> side_distance[X] < line -> side_distance[Y])
		{
			line -> side_distance[X] += line -> delta_distance[X];
			line -> position[X] += line -> step[X];
			side = 0;
		}
		else
		{
			line -> side_distance[Y] += line -> delta_distance[Y];
			line -> position[Y] = line -> step[Y];
			side = 1;
		}
		if (map[line -> position[X]][line -> position[Y]] != '0')
			hit = true;
	}
	if (side == 0)
		line->wall_distance = line->side_distance[X] - line->delta_distance[X];
	else
		line->wall_distance = line->side_distance[Y] - line->delta_distance[Y];
}

static void	calculate_line_render(t_line *line, int height)
{
	int	line_height;

	line_height = height / line -> wall_distance;
	line -> draw_start = -line_height / 2 + height / 2;
	if (line -> draw_start < 0)
	{
		line -> draw_start = 0;
	}
	line -> draw_end = line_height / 2 + height / 2;
	if (line -> draw_end >= height)
	{
		line -> draw_end = height - 1;
	}
}

void	calculate_line(
			t_game_data *game, t_line *line, double camera_x, int height)
{
	line -> position[X] = (int) game -> player -> position[X];
	line -> position[Y] = (int) game -> player -> position[Y];
	calculate_delta_distance(line, game -> camera, camera_x);
	calculate_line_distance(line, game -> player);
	calculate_wall_distance(line, game -> map);
	calculate_line_render(line, height);
}
