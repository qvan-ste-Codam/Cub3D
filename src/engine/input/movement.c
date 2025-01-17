/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 17:19:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/17 19:29:51 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"
#define MOVEMENT_SPEED 0.1

// TODO:
// - Fix validation. Don't know if the logic isn't correct,
// 	 or that it runs out of memory
// - Improve smoothnes and fix hangups

void	move_player(t_data *data, double new_pos_x, double new_pos_y)
{
	char		**map;
	t_player	*player;
	double		curr_pos_x;
	double		curr_pos_y;

	map = data->map;
	player = data->player;
	curr_pos_x = player->pos_x;
	curr_pos_y = player->pos_y;
	if (map[(int)curr_pos_y][(int)new_pos_x] != '1')
	{
		player->pos_x = new_pos_x;
	}
	if (map[(int)new_pos_y][(int)curr_pos_x] != '1')
	{
		player->pos_y = new_pos_y;
	}
}

void	move_forward(t_data *data)
{
	t_player	*player;
	double		view_dir_x;
	double		view_dir_y;
	double		new_pos_x;
	double		new_pos_y;

	view_dir_x = data->camera->view_dir_x;
	view_dir_y = data->camera->view_dir_y;
	player = data->player;
	new_pos_x = player -> pos_x
		+ view_dir_x * MOVEMENT_SPEED;
	new_pos_y = player -> pos_y
		+ view_dir_y * MOVEMENT_SPEED;
	player->pos_x = new_pos_x;
	player->pos_y = new_pos_y;
}

void	move_backwards(t_data *data)
{
	t_player	*player;
	double		view_dir_x;
	double		view_dir_y;
	double		new_pos_x;
	double		new_pos_y;

	view_dir_x = data->camera->view_dir_x;
	view_dir_y = data->camera->view_dir_y;
	player = data->player;
	new_pos_x = player -> pos_x
		- view_dir_x * MOVEMENT_SPEED;
	new_pos_y = player -> pos_y
		- view_dir_y * MOVEMENT_SPEED;
	player->pos_x = new_pos_x;
	player->pos_y = new_pos_y;
}

void	move_left(t_data *data)
{
	t_player	*player;
	double		view_dir_x;
	double		view_dir_y;
	double		new_pos_x;
	double		new_pos_y;

	view_dir_x = data->camera->view_dir_x;
	view_dir_y = data->camera->view_dir_y;
	player = data->player;
	new_pos_x = player -> pos_x
		- view_dir_y * MOVEMENT_SPEED;
	new_pos_y = player -> pos_y
		+ view_dir_x * MOVEMENT_SPEED;
	player->pos_x = new_pos_x;
	player->pos_y = new_pos_y;
}

void	move_right(t_data *data)
{
	t_player	*player;
	double		view_dir_x;
	double		view_dir_y;
	double		new_pos_x;
	double		new_pos_y;

	view_dir_x = data->camera->view_dir_x;
	view_dir_y = data->camera->view_dir_y;
	player = data->player;
	new_pos_x = player -> pos_x
		+ view_dir_y * MOVEMENT_SPEED;
	new_pos_y = player -> pos_y
		- view_dir_x * MOVEMENT_SPEED;
	player->pos_x = new_pos_x;
	player->pos_y = new_pos_y;
}
