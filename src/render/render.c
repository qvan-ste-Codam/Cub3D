/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 18:35:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/22 18:22:16 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"

static void	render_wall(mlx_image_t *screen, t_line *line,
	t_texture_props *texture_props, int height)
{
	int		color;
	int		screen_pos_y;
	int		texture_y;
	double	texture_doub_y;

	screen_pos_y = line->draw_start;
	texture_doub_y = (int)(line->draw_start - height / 2 + line->height / 2)
		* texture_props->step_size;
	while (screen_pos_y < line->draw_end)
	{
		texture_y = (int)texture_doub_y & (texture_props->texture->height - 1);
		texture_doub_y += texture_props->step_size;
		color = get_pixel_color(texture_props->texture,
				texture_props->x_pos, texture_y);
		mlx_put_pixel(screen, line->screen_pos_x, screen_pos_y, color);
		screen_pos_y++;
	}
}

static void	render_line(t_display *display, t_line *line)
{
	int	y;

	y = 0;
	while (y < line->draw_start)
	{
		mlx_put_pixel(display->frame, line->screen_pos_x,
			y, display->floor_color);
		y++;
	}
	render_wall(display->frame, line, line->texture_props, display->height);
	y = line->draw_end;
	while (y < display->height)
	{
		mlx_put_pixel(display->frame, line->screen_pos_x,
			y, display->ceiling_color);
		y++;
	}
}

static int	create_new_frame(t_display *display)
{
	mlx_image_t	*frame;

	mlx_delete_image(display->renderer, display->frame);
	frame = mlx_new_image(display->renderer, display->width, display->height);
	if (!frame)
	{
		return (FAILURE);
	}
	display->frame = frame;
	return (SUCCESS);
}

int	render_frame(t_display *display)
{
	int	i;

	i = 0;
	if (create_new_frame(display) == FAILURE)
	{
		return (FAILURE);
	}
	while (i < display -> width)
	{
		render_line(display, &display->lines[i]);
		i++;
	}
	mlx_image_to_window(display->renderer, display->frame, 0, 0);
	return (SUCCESS);
}
