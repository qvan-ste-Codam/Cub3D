/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 16:51:42 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/22 19:09:48 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"
#include <math.h>

static void	rotate_camera(t_camera *camera, t_data *data, double rotation_val)
{
	double		prev_view_dir_x;
	double		prev_plane_x;

	prev_view_dir_x = camera->view_dir_x;
	camera->view_dir_x = camera->view_dir_x * cos(rotation_val)
		- camera->view_dir_y * sin(rotation_val);
	camera->view_dir_y = prev_view_dir_x * sin(rotation_val)
		+ camera->view_dir_y * cos(rotation_val);
	prev_plane_x = camera->plane_x;
	camera->plane_x = camera->plane_x * cos(rotation_val)
		- camera->plane_y * sin(rotation_val);
	camera->plane_y = prev_plane_x * sin(rotation_val)
		+ camera->plane_y * cos(rotation_val);
	data -> display -> should_rerender = true;
}

void	handle_exit(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	(void) keydata;
	data = param;
	if (mlx_is_key_down(data->display->renderer, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->display->renderer);
	}
}

void	handle_input(t_data *data)
{
	double	speed;

	speed = data->display->renderer->delta_time * GAME_SPEED;
	if (mlx_is_key_down(data->display->renderer, MLX_KEY_LEFT))
		rotate_camera(data->camera, data, 1 * speed);
	if (mlx_is_key_down(data->display->renderer, MLX_KEY_RIGHT))
		rotate_camera(data->camera, data, -1 * speed);
	if (mlx_is_key_down(data->display->renderer, MLX_KEY_W))
		handle_move_forward(data, speed);
	if (mlx_is_key_down(data->display->renderer, MLX_KEY_S))
		handle_move_backwards(data, speed);
	if (mlx_is_key_down(data->display->renderer, MLX_KEY_A))
		handle_move_left(data, speed);
	if (mlx_is_key_down(data->display->renderer, MLX_KEY_D))
		handle_move_right(data, speed);
}
