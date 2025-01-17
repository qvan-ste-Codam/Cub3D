/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_distance.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 16:23:27 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/17 16:58:37 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	calculate_x_distance(t_ray *ray, t_player *player)
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

static void	calculate_y_distance(t_ray *ray, t_player *player)
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

void	calculate_line_distance(t_ray *ray, t_player *player)
{
	calculate_x_distance(ray, player);
	calculate_y_distance(ray, player);
}
