/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 15:56:19 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/19 21:53:45 by qvan-ste      ########   odam.nl         */
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

void	game_loop(void *param)
{
	t_data	*data;

	data = param;
	handle_input(data);
	if (data->display->rerender == true)
	{
		render_frame(data);
		draw_frame(data);
		data->display->rerender = false;
	}
	printf("%f\n", 1 / data->display->renderer->delta_time);
}
