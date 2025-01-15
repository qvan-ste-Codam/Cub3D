/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 21:50:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 21:50:22 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <stdlib.h>
#define X 0
#define Y 1

static int	get_resolution(t_display *display)
{
	mlx_t	*mlx;

	mlx_set_setting(MLX_HEADLESS, true);
	mlx = mlx_init(1, 1, "", false);
	if (!mlx)
	{
		return (-1);
	}
	mlx_get_monitor_size(0, &display -> width, &display -> height);
	mlx_terminate(mlx);
	mlx_set_setting(MLX_HEADLESS, false);
	return (SUCCESS);
}

t_display	*init_display(void)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (!display)
	{
		return (NULL);
	}
	if (get_resolution(display) != SUCCESS)
	{
		return (NULL);
	}
	display -> renderer = mlx_init(display -> width,
			display -> height, "Cub3D", false);
	if (!display -> renderer)
	{
		return (NULL);
	}
	display -> lines = malloc(display -> width * sizeof(t_line));
	if (!display -> lines)
	{
		return (NULL);
	}
	return (display);
}

t_player	*init_player(int player_x, int player_y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		return (NULL);
	}
	player -> position[X] = player_x;
	player -> position[Y] = player_y;
	return (player);
}

t_camera	*init_camera(int view_dir_x, int view_dir_y)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
	{
		return (NULL);
	}
	camera -> plane[X] = 0;
	camera -> plane[Y] = 0.66;
	camera -> view_dir[X] = view_dir_x;
	camera -> view_dir[Y] = view_dir_y;
	return (camera);
}
