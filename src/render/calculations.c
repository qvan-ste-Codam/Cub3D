/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculations.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 19:16:00 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/17 18:57:13 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>

static void	calculate_delta_distance(
	t_ray *ray, t_camera *camera, double camera_x)
{
	ray->dir_x = camera->view_dir_x + camera->plane_x * camera_x;
	ray->dir_y = camera->view_dir_y + camera->plane_y * camera_x;
	if (ray->dir_x == 0)
	{
		ray->delta_dist_x = INFINITY;
	}
	else
	{
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	}
	if (ray->dir_y == 0)
	{
		ray->delta_dist_y = INFINITY;
	}
	else
	{
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	}
}

static void	perform_dda(t_line *line, char **map)
{
	bool	hit_wall;
	t_ray	*ray;

	hit_wall = false;
	ray = line -> ray;
	while (hit_wall == false)
	{
		if (ray -> side_dist_x < ray -> side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_pos_x += ray->step_x;
			line->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_pos_y += ray->step_y;
			line->side = 1;
		}
		if (map[ray->map_pos_x][ray->map_pos_y] == '1')
			hit_wall = true;
	}
}

static void	calculate_wall_distance(
	t_line *line, double player_position_x, double player_position_y)
{
	t_ray	*ray;

	ray = line -> ray;
	if (line->side == 0)
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

static void	calculate_line_render(t_line *line, int height, t_player *player)
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
	if (line->side == 0)
		line->wall_x = player->pos_x + ray->wall_dist * ray->dir_y;
	else
		line->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	line->wall_x -= floor(line -> wall_x);
}

void	calculate_line(
	t_data *data, t_line *line)
{
	t_ray		*ray;
	t_player	*player;
	int			height;
	double		camera_x;

	ray = line->ray;
	player = data->player;
	height = data->display->height;
	camera_x = 2 * line->x_pos / (double)data->display->width - 1;
	ray->map_pos_x = player->pos_x;
	ray->map_pos_y = player->pos_y;
	calculate_delta_distance(ray, data->camera, camera_x);
	calculate_line_distance(ray, player);
	perform_dda(line, data->map);
	calculate_wall_distance(line, player->pos_x, player->pos_y);
	calculate_line_render(line, height, player);
}
