/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast_ray.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 16:23:27 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/22 12:49:50 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>

static void	calculate_delta_distance(
	t_ray *ray, t_camera *camera)
{
	ray->dir_x = camera->view_dir_x + camera->plane_x * ray->camera_x;
	ray->dir_y = camera->view_dir_y + camera->plane_y * ray->camera_x;
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

static void	calculate_side_distance_x(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_pos_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x
			= (ray->map_pos_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
}

static void	calculate_side_distance_y(t_ray *ray, t_player *player)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_pos_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y
			= (ray->map_pos_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

static void	perform_dda(t_ray *ray, char **map)
{
	bool	hit_wall;

	hit_wall = false;
	while (hit_wall == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_pos_x += ray->step_x;
			ray->side = VERTICAL;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_pos_y += ray->step_y;
			ray->side = HORIZONTAL;
		}
		if (map[ray->map_pos_x][ray->map_pos_y] == '1')
			hit_wall = true;
	}
}

void	cast_ray(t_ray *ray, t_player *player, t_camera *camera, char **map)
{
	ray->map_pos_x = player->pos_x;
	ray->map_pos_y = player->pos_y;
	calculate_delta_distance(ray, camera);
	calculate_side_distance_x(ray, player);
	calculate_side_distance_y(ray, player);
	perform_dda(ray, map);
}
