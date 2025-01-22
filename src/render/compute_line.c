/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_line.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 19:16:00 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/22 18:58:55 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>

static void	compute_wall_distance(
	t_ray *ray)
{
	if (ray->side == VERTICAL)
	{
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	}
	else
	{
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
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
	t_line *line, t_ray *ray, int height)
{
	line->height = (int)(height / ray->wall_dist);
	line->draw_start = -line->height / 2 + height / 2;
	if (line->draw_start < 0)
	{
		line->draw_start = 0;
	}
	line->draw_end = line->height / 2 + height / 2;
	if (line->draw_end >= height)
	{
		line->draw_end = height - 1;
	}
}

static void	compute_texture_properties(
	t_line *line, t_ray *ray, t_player *player, mlx_texture_t **textures)
{
	int				texture_x_pos;
	double			wall_hit_x;
	mlx_texture_t	*texture;

	if (ray->side == VERTICAL)
	{
		wall_hit_x = player->pos_y + ray->wall_dist * ray->dir_y;
	}
	else
	{
		wall_hit_x = player->pos_x + ray->wall_dist * ray->dir_x;
	}
	wall_hit_x -= floor(wall_hit_x);
	texture = textures[line->dir];
	line->texture_props->texture = texture;
	line->texture_props->step_size = 1.0 * texture->height / line->height;
	texture_x_pos = wall_hit_x * texture->width;
	if (line->dir == NORTH || line->dir == EAST)
	{
		texture_x_pos = texture->width - texture_x_pos - 1;
	}
	line->texture_props->x_pos = texture_x_pos;
}

void	compute_line(t_data *data, t_line *line)
{
	cast_ray(line->ray, data->player, data->camera, data->map);
	compute_wall_distance(line->ray);
	determine_wall_direction(line, line->ray);
	compute_line_properties(line, line->ray, data->display->height);
	compute_texture_properties(line, line->ray,
		data->player, data->display->textures);
}
