/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculations.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 19:16:00 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/19 21:55:39 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>

static void	compute_wall_distance(
	t_ray *ray, double player_position_x, double player_position_y)
{
	if (ray->side == VERTICAL)
	{
		ray->wall_dist = (ray->map_pos_x - player_position_x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	}
	else
	{
		ray->wall_dist = (ray->map_pos_y - player_position_y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
	}
}

static void	determine_wall_direction(t_line *line, t_ray *ray)
{
	if (ray->side == VERTICAL)
	{
		if (ray->dir_x > 0)
			line->dir = EAST;
		else
			line->dir = WEST;
	}
	else
	{
		if (ray->dir_y > 0)
			line->dir = SOUTH;
		else
			line->dir = NORTH;
	}
}

static void	compute_line_properties(
	t_line *line, int height, t_player *player)
{
	int		line_height;
	t_ray	*ray;

	ray = line->ray;
	line_height = (int)(height / ray->wall_dist);
	line->render_start = -line_height / 2 + height / 2;
	if (line->render_start < 0)
	{
		line->render_start = 0;
	}
	line->render_end = line_height / 2 + height / 2;
	if (line->render_end >= height)
	{
		line->render_end = height - 1;
	}
	if (ray->side == VERTICAL)
		line->texture_pos_x = player->pos_x + ray->wall_dist * ray->dir_y;
	else
		line->texture_pos_x = player->pos_x + ray->wall_dist * ray->dir_x;
	line->texture_pos_x -= floor(line -> texture_pos_x);
}

void	render_line(t_data *data, t_line *line)
{
	cast_ray(line->ray, data->player, data->camera, data->map);
	compute_wall_distance(line->ray, data->player->pos_x, data->player->pos_y);
	determine_wall_direction(line, line->ray);
	compute_line_properties(line, data->display->height, data->player);
}
