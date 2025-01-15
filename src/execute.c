/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 15:56:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 21:32:04 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../include/cub3D.h"
#include <stdio.h>

void	cast_ray(t_game_data *game)
{
	int		x;
	double	camera_x;
	t_line	*line;

	x = 0;
	while (x < game -> display -> width)
	{
		line = &game -> display -> lines[x];
		line -> x_position = x;
		camera_x = 2 * x / (double) game -> display -> width - 1;
		calculate_line(game, line, camera_x, game -> display -> height);
		x++;
	}
}

int	execute_game(t_game_data *game)
{
	t_display	*display;

	display = game -> display;
	display -> screen = mlx_new_image(display -> renderer,
			display -> width, display -> height);
	mlx_image_to_window(display -> renderer, display -> screen, 0, 0);
	cast_ray(game);
	mlx_loop(display -> renderer);
	mlx_terminate(display -> renderer);
	return (0);
}
