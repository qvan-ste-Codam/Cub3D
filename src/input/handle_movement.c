/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 17:19:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/22 19:06:43 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	attempt_move_player(
	t_data *data, double new_pos_x, double new_pos_y)
{
	t_player	*player;

	player = data->player;
	if (data->map[(int)new_pos_x][(int)player->pos_y] != '1')
	{
		player->pos_x = new_pos_x;
	}
	if (data->map[(int)player->pos_x][(int)new_pos_y] != '1')
	{
		player->pos_y = new_pos_y;
	}
	data->display->should_rerender = true;
}

void	handle_move_forward(t_data *data, double speed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = data->player->pos_x
		+ data->camera->view_dir_x * speed;
	new_pos_y = data->player->pos_y
		+ data->camera->view_dir_y * speed;
	attempt_move_player(data, new_pos_x, new_pos_y);
}

void	handle_move_backwards(t_data *data, double speed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = data->player->pos_x
		- data->camera->view_dir_x * speed;
	new_pos_y = data->player->pos_y
		- data->camera->view_dir_y * speed;
	attempt_move_player(data, new_pos_x, new_pos_y);
}

void	handle_move_left(t_data *data, double speed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = data->player->pos_x
		- data->camera->view_dir_y * speed;
	new_pos_y = data->player->pos_y
		+ data->camera->view_dir_x * speed;
	attempt_move_player(data, new_pos_x, new_pos_y);
}

void	handle_move_right(t_data *data, double speed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = data->player->pos_x
		+ data->camera->view_dir_y * speed;
	new_pos_y = data->player->pos_y
		- data->camera->view_dir_x * speed;
	attempt_move_player(data, new_pos_x, new_pos_y);
}
