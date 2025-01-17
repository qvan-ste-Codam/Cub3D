/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 15:56:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/17 17:25:30 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"

void	render_frame(t_data *data)
{
	int			x;
	t_display	*display;
	t_line		*line;

	x = 0;
	display = data->display;
	while (x < display->width)
	{
		line = &data->display->lines[x];
		line->x_pos = x;
		calculate_line(data, line);
		render_line(data->display->screen, line, data->display->height);
		x++;
	}
}

void	game_loop(void *param)
{
	t_data	*data;

	data = param;
	render_frame(data);
}

int	execute_game(t_data *data)
{
	t_display	*display;

	display = data->display;
	display->screen = mlx_new_image(display->renderer,
			display->width, display->height);
	mlx_image_to_window(display->renderer, display->screen, 0, 0);
	mlx_loop_hook(display->renderer, &game_loop, data);
	mlx_key_hook(display->renderer, &handle_input, data);
	mlx_loop(display->renderer);
	mlx_terminate(display->renderer);
	return (0);
}
