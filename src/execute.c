/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 15:56:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/20 22:38:19 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../include/cub3D.h"
#include <stdio.h>

static void	render_frame(t_data *data)
{
	int			i;
	t_display	*display;
	t_line		*line;

	i = 0;
	display = data->display;
	while (i < display->width)
	{
		line = &data->display->lines[i];
		render_line(data, line);
		i++;
	}
}

static void	game_loop(void *param)
{
	t_data	*data;

	data = param;
	handle_input(data);
	if (data->display->should_rerender == true)
	{
		render_frame(data);
		draw_frame(data->display);
		data->display->should_rerender = false;
	}
}

void	execute(t_data *data)
{
	mlx_t	*renderer;

	renderer = data->display->renderer;
	mlx_key_hook(renderer, &handle_exit, data);
	mlx_loop_hook(renderer, &game_loop, data);
	mlx_loop(renderer);
	mlx_terminate(renderer);
}
