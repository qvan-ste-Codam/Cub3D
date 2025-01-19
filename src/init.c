/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 21:50:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/19 20:24:56 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libs/libft/include/libft.h"
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
	mlx_get_monitor_size(0, &display->width, &display->height);
	mlx_terminate(mlx);
	mlx_set_setting(MLX_HEADLESS, false);
	return (SUCCESS);
}

static t_line	*init_lines(int width)
{
	int		i;
	t_line	*lines;
	t_ray	*ray;

	i = 0;
	lines = ft_calloc(width, sizeof(t_line));
	if (!lines)
	{
		return (NULL);
	}
	while (i < width)
	{
		ray = ft_calloc(1, sizeof(t_ray));
		if (!ray)
		{
			return (NULL);
		}
		lines[i].ray = ray;
		lines[i].screen_pos_x = i;
		lines[i].ray->camera_x = 2 * i / (double)width - 1;
		i++;
	}
	return (lines);
}

t_display	*init_display(void)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (!display)
	{
		return (NULL);
	}
	ft_bzero(display, sizeof(t_display));
	if (get_resolution(display) != SUCCESS)
	{
		return (NULL);
	}
	display->renderer = mlx_init(display->width,
			display->height, "Cub3D", false);
	if (!display -> renderer)
	{
		return (NULL);
	}
	display->lines = init_lines(display->width);
	if (!display -> lines)
	{
		return (NULL);
	}
	display->rerender = true;
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
	player->pos_x = player_x;
	player->pos_y = player_y;
	return (player);
}

t_camera	*init_camera(int view_direction_x, int view_direction_y)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
	{
		return (NULL);
	}
	camera->plane_x = 0;
	camera->plane_y = 0.66;
	camera->view_dir_x = view_direction_x;
	camera->view_dir_y = view_direction_y;
	return (camera);
}
